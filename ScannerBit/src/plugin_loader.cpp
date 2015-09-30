//  GAMBIT: Global and Modular BSM Inference Tool
//  *********************************************
///  \file
///
///  Loader singleton class for scanner plugins
///
///  *********************************************
///
///  Authors (add name and date if you modify):
//
///  \author Gregory Martinez
///          (gregory.david.martinez@gmail.com)
///  \date 2013 August
///  \date 2014 Feb
///
///  \author Pat Scott
///          (p.scott@imperial.ac.uk)   
///  \date 2014 Dec
///
///  *********************************************

#include <cstdlib>
#include <iomanip>
#include "gambit/ScannerBit/scanner_utils.hpp"
#include "gambit/ScannerBit/plugin_comparators.hpp"
#include "gambit/ScannerBit/plugin_loader.hpp"
#include "gambit/cmake/cmake_variables.hpp"
#include "gambit/Utils/table_formatter.hpp"
#include "gambit/Utils/screen_print_utils.hpp"

namespace Gambit
{

    namespace Scanner
    {

        namespace Plugins
        {
            inline std::string print_plugins(std::map< std::string, std::map<std::string, std::vector<Plugin_Details> > >::const_iterator plugins)
            {
                typedef std::map<std::string, std::vector<Plugin_Details> > plugin_map;
                typedef std::map<std::string, plugin_map> plugin_mapmap;
                
                table_formatter table(plugins->first + " PLUGINS", "VERSION", "STATUS");
                table.capitalize_title();
                table.padding(1);
                
                for (auto it = plugins->second.begin(); it != plugins->second.end(); ++it)
                {
                    for (auto jt = it->second.begin(); jt != it->second.end(); ++jt)
                    {
                        const str firstentry = (jt == it->second.begin() ? it->first : "");
                        table << firstentry;
                        table << jt->version;
                        if (jt->status == "ok")
                            table.green() << jt->status;
                        else
                            table.red() << jt->status;
                    }
                }
                
                return table.str();
            }
            
            Plugin_Loader::Plugin_Loader() : path(GAMBIT_DIR "/ScannerBit/lib/")
            {
                std::string p_str;
                if (FILE* p_f = popen((std::string("ls ") + path).c_str(), "r"))
                {
                    char path_buffer[1024];
                    int p_n;
                    while ((p_n = fread(path_buffer, 1, sizeof path_buffer, p_f)) > 0)
                    {
                        std::stringstream p_ss(std::string(path_buffer, p_n));
                        while (p_ss >> p_str)
                        {
                            if (p_str.find(".so") != std::string::npos && p_str.find(".so.") == std::string::npos)
                                loadLibrary (path + p_str);
                        }
                    }
                    
                    pclose(p_f);
                    
                    loadExcluded(GAMBIT_DIR "/scratch/scanbit_excluded_libs.yaml");
                    
                    flags_node = YAML::LoadFile(GAMBIT_DIR "/scratch/scanbit_flags.yaml");
                    process(GAMBIT_DIR "/scratch/scanbit_linked_libs.yaml", GAMBIT_DIR "/scratch/scanbit_reqd_entries.yaml", GAMBIT_DIR "/scratch/scanbit_flags.yaml");
                }
            }

            void Plugin_Loader::process(const std::string &libFile, const std::string &plugFile, const std::string &flagFile)
            {
                YAML::Node libNode = YAML::LoadFile(libFile);
                YAML::Node plugNode = YAML::LoadFile(plugFile);
                YAML::Node flagNode = YAML::LoadFile(flagFile);
                
                for (auto it = plugins.begin(), end = plugins.end(); it != end; it++)
                {
                    it->get_status(libNode, plugNode, flags_node);
                    plugin_map[it->type][it->plugin].push_back(*it);
                    total_plugin_map[it->type][it->plugin].push_back(*it);
                    //std::cout << it->printFull() << std::endl;
                }
                
                for (auto it = excluded_plugins.begin(), end = excluded_plugins.end(); it != end; it++)
                {
                    it->get_status(libNode, plugNode, flagNode);
                    excluded_plugin_map[it->type][it->plugin].push_back(*it);
                    total_plugin_map[it->type][it->plugin].push_back(*it);
                    //std::cout << it->printFull() << std::endl;
                }
            }
            
            void Plugin_Loader::loadExcluded (const std::string& file)
            {
                    YAML::Node node = YAML::LoadFile(file);
                    
                if (node.IsMap())
                {
                    for (auto it = node.begin(), end = node.end(); it != end; it++)
                    {
                        std::string lib = it->first.as<std::string>();
                        std::vector<Plugin_Details> excluded_plugins_temp;
                        std::vector<std::string> reason;
                        if (it->second.IsMap())
                        {
                            if (it->second["plugins"])
                            {
                                for (auto it2 = it->second["plugins"].begin(), end2 = it->second["plugins"].end(); it2 != end2; ++it2)
                                {
                                    Plugin_Details temp(it2->as<std::string>());

                                    temp.path = path + lib;
                                    temp.status = "excluded";
                                    //total_plugins.push_back(temp);
                                    excluded_plugins_temp.push_back(temp);
                                }
                            }
                            
                            if (it->second["reason"])
                            {
                                if(it->second["reason"].IsScalar())
                                {
                                    reason.push_back(it->second["reason"].as<std::string>());
                                }
                                if(it->second["reason"].IsMap())
                                {
                                    for (auto it2 = it->second["reason"].begin(), end2 = it->second["reason"].end(); it2 != end2; ++it2)
                                    {
                                        reason.push_back(it2->first.as<std::string>() + ":  " + it2->second.as<std::string>());
                                    }
                                }
                            }
                            
                            for (auto it2 = excluded_plugins_temp.begin(), end2 = excluded_plugins_temp.end(); it2 != end2; ++it2)
                            {
                                it2->status = "excluded";
                                it2->reason.insert(it2->reason.end(), reason.begin(), reason.end());
                            }
                            
                            excluded_plugins.insert(excluded_plugins.end(), excluded_plugins_temp.begin(), excluded_plugins_temp.end());
                            total_plugins.insert(total_plugins.end(), excluded_plugins_temp.begin(), excluded_plugins_temp.end());
                            
                        }
                    }
                }
            }
            
            void Plugin_Loader::loadLibrary (const std::string &p_str, const std::string &plug)
            {
                std::string str;
                if (FILE* f = popen((std::string("nm ") + p_str + std::string(" | grep \"__gambit_plugin_pluginInit_\"")).c_str(), "r"))
                {
                    char buffer[1024];
                    int n;
                    
                    while ((n = fread(buffer, 1, sizeof buffer, f)) > 0)
                    {
                        std::stringstream ss(std::string(buffer, n));
                        while(std::getline(ss, str))
                        {
                            std::string::size_type pos = str.find("__gambit_plugin_pluginInit_");
                            
                            if (pos != std::string::npos && 
                                    (str.rfind(" T ", pos) != std::string::npos || str.rfind(" t ", pos) != std::string::npos))
                            {
                                Plugin_Details temp(str.substr(pos + 27, str.rfind("__") - pos - 27));
                                
                                if (plug == "" || temp.plugin == plug)
                                {
                                    temp.path = p_str;
                                    plugins.push_back(temp);
                                    total_plugins.push_back(temp);
                                }
                            }
                        }
                    }
                    
                    pclose(f);
                }
            }
            
            std::vector<std::string> Plugin_Loader::print_plugin_names(const std::string &plug_type) const
            {
                std::vector<std::string> vec;
                
                if (plug_type != "")
                {
                    auto plugins = total_plugin_map.find(plug_type);
                    if (plugins == total_plugin_map.end())
                    {
                        return vec;
                    }
                    else
                    {
                        for (auto it = plugins->second.begin(), end = plugins->second.end(); it != end; ++it)
                        {
                            vec.push_back(it->first);
                        }
                    }
                }
                else
                {
                    for (auto it = total_plugin_map.begin(), end = total_plugin_map.end(); it != end; it++)
                    {
                        for (auto it2 = it->second.begin(), end2 = it->second.end(); it2 != end2; ++it2)
                        {
                            vec.push_back(it2->first);
                        }
                    }
                }
                
                return vec;
            }
            
            std::string Plugin_Loader::print_all(const std::string &plug_type) const
            {
                if (plug_type != "")
                {
                    auto plugins = total_plugin_map.find(plug_type);
                    if (plugins == total_plugin_map.end())
                    {
                        return "";
                    }
                    else
                    {
                        return print_plugins(plugins);
                    }
                }
                else
                {
                    for (auto it = total_plugin_map.begin(), end = total_plugin_map.end(); it != end; it++)
                    {
                        return print_plugins(it);
                    }
                }
                
                return "";
            }
            
            int Plugin_Loader::print_all_to_screen (const std::string &name) const
            {
                std::string output = print_all(name);
                if (output == "")
                    return 1;
                
                print_to_screen(output, name);
                return 0;
            }
            
            std::string Plugin_Loader::print_plugin(const std::string &name) const
            {
                std::vector<Scanner::Plugins::Plugin_Details> vec;
                std::stringstream output;
                for (auto it_map = getPluginsMap().begin(), end = getPluginsMap().end(); it_map!= end; it_map++)
                {
                    auto it = it_map->second.find(name);
                    if (it != it_map->second.end())
                    {
                        vec.insert(vec.begin(), it->second.begin(), it->second.end());
                    }
                }
                
                if (vec.size() == 0)
                {
                    return "";
                }
                else
                {
                    for (auto it = vec.begin(), end = vec.end(); it != end; it++)
                    {
                        output << it->printFull() << std::endl;
                    }
                }
                
                return output.str();
            }
            
            std::string Plugin_Loader::print_plugin(const std::string &type, const std::string &plugin) const
            {
                std::stringstream output;
                std::vector<Scanner::Plugins::Plugin_Details> vec;
                
                if((getPluginsMap().find(type) == getPluginsMap().end()) || (getPluginsMap().at(type).find(plugin) == getPluginsMap().at(type).end()))
                {
                    return "";
                }
                
                for (auto it = getPluginsMap().at(type).at(plugin).begin(), end = getPluginsMap().at(type).at(plugin).end(); it != end; it++)
                {
                    vec.push_back(*it);
                }
                
                if (vec.size() == 0)
                {
                    return "";
                }
                else
                {
                    for (auto it = vec.begin(), end = vec.end(); it != end; it++)
                    {
                        output << it->printFull() << std::endl;
                    }
                }
                
                return output.str();
            }
            
            int Plugin_Loader::print_plugin_to_screen (const std::string &name) const
            {
                std::string output = print_plugin(name);
                if (output == "")
                    return 1;
                
                print_to_screen(output, name);
                return 0;
            }
            
            int Plugin_Loader::print_plugin_to_screen (const std::string &type, const std::string &name) const
            {
                std::string output = print_plugin(type, name);
                if (output == "")
                    return 1;
                
                print_to_screen(output, name);
                return 0;
            }
            
            int Plugin_Loader::print_plugin_to_screen (const std::vector<std::string> &names) const
            {
                std::string output;
                for (auto it = names.begin(), end = names.end(); it != end; ++it)
                {
                    output += print_plugin(*it) + "\n";
                }
                
                if (output == "")
                    return 1;
                
                print_to_screen(output, names[0]);
                return 0;
            }
            
            Plugin_Details &Plugin_Loader::find (const std::string &type, const std::string &plugin, const std::string &version, const std::string &lib) const
            {
                std::vector<Plugin_Details_Ref> plugins;

                if((plugin_map.find(type) == plugin_map.end()) || (plugin_map.at(type).find(plugin) == plugin_map.at(type).end()))
                {
                    scan_err << "There is no plugin named \"" << plugin <<"\" of type \"" << type << "\"" << scan_end;
                }
                
                for (auto it = plugin_map.at(type).at(plugin).begin(), end = plugin_map.at(type).at(plugin).end(); it != end; it++)
                {
                    if (VersionCompare(version)(*it) && (lib == "" || lib == it->path))
                        plugins.push_back(*it);
                }
                
                if (plugins.size() > 1)
                {
                    std::sort(plugins.begin(), plugins.end(), Plugin_Version_Supersedes);
                    auto it2 = plugins.begin();
                    for (auto it = it2 + 1, end = plugins.end(); it != end; it++)
                    {
                        if (*it == *it2)
                        {
                            scan_err << "There are two plugins that met the input"
                                    << " criteria in the inifile:\n" << static_cast<Plugin_Details &>(*it).print()
                                    << "\n and ... \n\n" << static_cast<Plugin_Details &>(*it).print() << scan_end;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else if (plugins.size() == 0)
                {
                    scan_err << "Plugin \"" << plugin << "\" of type \"" << type << "\" and " 
                            << " version \"" << version << "\" is not found." << scan_end;
                    plugins.resize(1);
                }
                
                return plugins[0];
            }

            void pluginInfo::iniFile(const Options &options_in, printer_interface &printerIn)
            {
                options = options_in;
                printer = &printerIn;
                if (options.getNode().IsMap())
                {
                    for (auto it = options.getNode().begin(), end = options.getNode().end(); it != end; it++)
                    {
                        std::string plug_type = it->first.as<std::string>();
                        
                        if (it->second.IsMap() && plug_type[plug_type.length()-1] == 's' && plug_type != "priors" && plug_type != "parameters")
                        {
                            for (auto it_p = it->second.begin(), end = it->second.end(); it_p != end; it_p++)
                            {
                                std::string plug_tag = it_p->first.as<std::string>();
                                
                                Proto_Plugin_Details temp;
                                
                                if (it_p->second["plugin"])
                                {
                                    temp.plugin = it_p->second["plugin"].as<std::string>();
                                }
                                else
                                {
                                    scan_warn << "Plugin name is not defined under the \"" << it->first << "\" tag.  "
                                                << "using the tag \"" << it_p->first.as<std::string>()
                                                << "\" as the plugin name." << scan_end;
                                    temp.plugin = it_p->first.as<std::string>();
                                }
                                
                                if (it_p->second["version"])
                                    temp.version = it_p->second["version"].as<std::string>();
                                
                                if (it_p->second["plugin_path"])
                                {
                                    temp.path = it_p->second["plugin_path"].as<std::string>();
                                    plugins.loadLibrary(temp.path, temp.plugin);
                                }
                                        
                                selectedPlugins[plug_type.substr(0, plug_type.length()-1)][plug_tag] = temp;
                            }
                        }
                    }
                }
                else
                {
                    scan_err << "Plugins subsection is not of the \"Map\" YAML format." << scan_end;
                }
            }
            
            Plugins::Plugin_Interface_Details pluginInfo::operator()(const std::string &type, const std::string &tag)
            {
                if (selectedPlugins.find(type) != selectedPlugins.end() && selectedPlugins[type].find(tag) != selectedPlugins[type].end())
                {
                    Proto_Plugin_Details &detail = selectedPlugins[type][tag];
                    return Plugin_Interface_Details(plugins.find(type, detail.plugin, detail.version, detail.path), printer, options.getOptions(type + "s", tag).getNode());
                }
                else
                {
                    scan_err << "Plugin \"" << tag << "\" of type \"" << type << "\" is not defined under the \"Scanner\""
                            << " subsection in the inifile" << scan_end;
                                
                    return Plugin_Interface_Details(plugins.find(type, "", "", ""), printer, options.getOptions(type + "s", tag).getNode());
                }
            }
            
            void pluginInfo::dump()
            {
                for (auto it = resume_data.begin(), end = resume_data.end(); it != end; ++it)
                {
                    std::ofstream out((std::string(GAMBIT_DIR) + "/scratch/" + it->first).c_str(), std::ofstream::binary);
                    for (auto v_it = it->second.begin(), v_end = it->second.end(); v_it != v_end; ++v_it)
                    {
                        (*v_it)->print(out);
                    }
                }
                
                //printer->finalise(true);
                std::cout << "Gambit has finished early!" << std::endl;
            }
            
            pluginInfo::~pluginInfo()
            {
                for (auto it = resume_data.begin(), end = resume_data.end(); it != end; ++it)
                {
                    for (auto v_it = it->second.begin(), v_end = it->second.end(); v_it != v_end; ++v_it)
                    {
                        delete (*v_it);
                    }
                }
                
                for (auto it = resume_streams.begin(), end = resume_streams.end(); it != end; ++it)
                {
                    delete it->second;
                }
            }
            
            pluginInfo plugin_info;
        }
    }
}

