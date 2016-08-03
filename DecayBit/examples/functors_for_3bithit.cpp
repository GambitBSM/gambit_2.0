//   GAMBIT: Global and Modular BSM Inference Tool
//   *********************************************
///  \file                                       
///                                               
///  Explicit functor template class              
///  instantiations needed by standalone program  
///  3bithit.                          
///                                               
///  This file was automatically generated by     
///  standalone_facilitator.py. Do not modify.    
///  The content is harvested from the rollcall   
///  headers registered in module_rollcall.hpp    
///  and the types registered in                  
///  types_rollcall.hpp.                          
///                                               
///  *********************************************
///                                               
///  Authors:                                     
///                                               
///  \author The GAMBIT Collaboration            
///  \date 05:14PM on August 03, 2016
///                                               
///  *********************************************
                                                  
#include "gambit/Elements/functor_definitions.hpp"
#include "gambit/Elements/types_rollcall.hpp"   
#include "gambit/Elements/all_functor_types.hpp"
                                                  
namespace Gambit                                  
{                                                 
  // Non-module types                             
  template class module_functor<void>;            
  template class module_functor<const Spectrum*>;
  template class module_functor<fh_HiggsMassObs>;
  template class module_functor<int>;
  template class module_functor<float>;
  template class module_functor<hb_ModelParameters>;
  template class module_functor<fh_FlavorObs>;
  template class module_functor<std::vector<std::string>>;
  template class module_functor<fh_HiggsProd>;
  template class module_functor<std::vector<double>>;
  template class module_functor<daFunk::Funk>;
  template class module_functor<SLHAstruct>;
  template class module_functor<parameters>;
  template class module_functor<bool>;
  template class module_functor<Pythia8::Event>;
  template class module_functor<fh_PrecisionObs>;
  template class module_functor<SMInputs>;
  template class module_functor<fh_Couplings>;
  template class module_functor<HEPUtils::Event>;
  template class module_functor<map_str_dbl>;
  template class module_functor<triplet<double>>;
  template class module_functor<fptr_dd>;
  template class module_functor<std::vector<float>>;
  template class module_functor<DM_nucleon_couplings>;
  template class module_functor<fptr>;
  template class module_functor<DecayTable>;
  template class module_functor<const SubSpectrum*>;
  template class module_functor<double>;
  template class module_functor<SubSpectrum*>;
  template class module_functor<Spectrum>;
  template class module_functor<DecayTable::Entry>;
  template class module_functor<ModelParameters>;
  template class module_functor<str>;
  template class module_functor<Flav_KstarMuMu_obs>;
  template class module_functor<fh_MSSMMassObs>;
  // Module types
  template class module_functor<DecayBit::mass_es_pseudonyms>;
}

// Instantiate the backend functor templates for all required types 
BOOST_PP_SEQ_FOR_EACH(INSTANTIATE_BACKEND_FUNCTOR_TEMPLATE,,BACKEND_FUNCTOR_TYPES)

// Define the functor helper functions for this standalone compilation unit
// Define standalone version of functor signal helpers (that do nothing)
namespace Gambit                                                      
{                                                                     
  namespace FunctorHelp                                               
  {                                                                   
    void check_for_shutdown_signal(module_functor_common&) {}         
    bool emergency_shutdown_begun() { return false; }                 
    void entering_multithreaded_region(module_functor_common&) {}     
    void leaving_multithreaded_region(module_functor_common&) {}      
  }                                                                   
}
