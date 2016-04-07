#ifndef __wrapper_ResonanceGmZ_decl_Pythia_8_212_EM_h__
#define __wrapper_ResonanceGmZ_decl_Pythia_8_212_EM_h__

#include <cstddef>
#include "forward_decls_wrapper_classes.h"
#include "gambit/Backends/wrapperbase.hpp"
#include "abstract_ResonanceGmZ.h"

#include "identification.hpp"

namespace CAT_3(BACKENDNAME,_,SAFE_VERSION)
{
    
    namespace Pythia8
    {
        
        class ResonanceGmZ : public WrapperBase
        {
                // Member variables: 
            public:
                // -- Static factory pointers: 
                static Pythia8::Abstract_ResonanceGmZ* (*__factory0)(int);
        
                // -- Other member variables: 
        
                // Member functions: 
        
                // Wrappers for original constructors: 
            public:
                ResonanceGmZ(int idResIn);
        
                // Special pointer-based constructor: 
                ResonanceGmZ(Pythia8::Abstract_ResonanceGmZ* in);
        
                // Copy constructor: 
                ResonanceGmZ(const ResonanceGmZ& in);
        
                // Assignment operator: 
                ResonanceGmZ& operator=(const ResonanceGmZ& in);
        
                // Destructor: 
                ~ResonanceGmZ();
        
                // Returns correctly casted pointer to Abstract class: 
                Pythia8::Abstract_ResonanceGmZ* get_BEptr() const;
        
        };
    }
    
}


#include "gambit/Backends/backend_undefs.hpp"

#endif /* __wrapper_ResonanceGmZ_decl_Pythia_8_212_EM_h__ */
