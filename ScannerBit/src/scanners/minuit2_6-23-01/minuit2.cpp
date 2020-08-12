//  GAMBIT: Global and Modular BSM Inference Tool
//  *********************************************
///  \file
///
///  ScannerBit interface to Minuit2
///
///  Header file
///
///  *********************************************
///
///  Authors (add name and date if you modify):
///
///  \author Andrew Fowlie
///          (andrew.j.fowlie@qq.com)
///  \date 2020 August
///
///  *********************************************

#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>  // For debugging only

#include "gambit/ScannerBit/scanner_plugin.hpp"
#include "gambit/ScannerBit/scanners/minuit2/minuit2.hpp"
#include "gambit/Utils/yaml_options.hpp"
#include "gambit/Utils/util_functions.hpp"

#include "Math/IFunction.h"
#include "Minuit2/Minuit2Minimizer.h"
#include "Math/Functor.h"
#include "Math/MinimizerOptions.h"

scanner_plugin(minuit2, version(6, 23, 01))
{
   reqd_libraries("Minuit2", "Minuit2Math");
   reqd_headers("Math/IFunction.h", "Minuit2/Minuit2Minimizer.h", "Math/Functor.h", "Math/MinimizerOptions.h");

   int plugin_main(void)
   {
      // Retrieve the dimensionality of the scan
      const int dim = get_dimension();

      Gambit::Scanner::like_ptr loglike_hypercube = get_purpose(get_inifile_value<std::string>("like"));

      double offset = get_inifile_value<double>("likelihood: lnlike_offset", 0.);
      loglike_hypercube->setPurposeOffset(offset);
  
      // minuit2 algorithm options
      const auto algorithm{get_inifile_value<std::string>("algorithm", "minimize")};
      const auto max_loglike_calls{get_inifile_value<int>("max_loglike_calls", 100000)};   
      const auto tolerance{get_inifile_value<double>("tolerace", 0.0001)};   
      const auto print_level{get_inifile_value<int>("print_level", 1)};   
      const auto start{get_inifile_value<double>("unit_hypercube_start", 0.5)}; 
      const auto step{get_inifile_value<double>("unit_hypercube_step", 0.01)}; 

      ROOT::Math::Minimizer* min = new ROOT::Minuit2::Minuit2Minimizer(algorithm.c_str());
      min->SetMaxFunctionCalls(max_loglike_calls);
      min->SetTolerance(tolerance);
      min->SetPrintLevel(print_level);

      auto chi_squared = [&loglike_hypercube, dim] (const double* x)
      {
        std::vector<double> v;
        for (int i = 0; i < dim; i++)
        {
          v.push_back(x[i]);
        }
        return -2. * loglike_hypercube(v);
      };

      ROOT::Math::Functor f(chi_squared, dim); // TODO this is surely wrong!
      min->SetFunction(f);

      // set the free variables to be minimized
      for (int i = 0; i < dim; i++)
      {
        std::string name = "x_" + std::to_string(i);
        min->SetVariable(i, name, start, step);
      }

      // do the minimization
      min->Minimize();

      std::cout << "minimum chi-squared = " <<  min->MinValue() << std::endl;

      const double *best_fit_hypercube = min->X();
      for (int i = 0; i < dim; i++)
      {
        std::cout << "best-fit hypercube " << i << " = "
                  << best_fit_hypercube[i] << std::endl;
      }

      // convert result to physical parameters
      // TODO

      // manually delete the pointer
      delete min;

      // success if reached end
      return 0;
   }
}

