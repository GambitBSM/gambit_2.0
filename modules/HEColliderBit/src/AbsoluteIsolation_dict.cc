//
// File generated by rootcint at Thu Jul 18 14:36:26 2013

// Do NOT change. Changes will be lost next time file is generated
//

#define R__DICTIONARY_FILENAME AbsoluteIsolation_dict
#include "RConfig.h" //rootcint 4834
#if !defined(R__ACCESS_IN_SYMBOL)
//Break the privacy of classes -- Disabled for the moment
#define private public
#define protected public
#endif

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;
#include "AbsoluteIsolation_dict.h"

#include "TClass.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"

// START OF SHADOWS

namespace ROOT {
   namespace Shadow {
   } // of namespace Shadow
} // of namespace ROOT
// END OF SHADOWS

namespace ROOT {
   void AbsoluteIsolation_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void *new_AbsoluteIsolation(void *p = 0);
   static void *newArray_AbsoluteIsolation(Long_t size, void *p);
   static void delete_AbsoluteIsolation(void *p);
   static void deleteArray_AbsoluteIsolation(void *p);
   static void destruct_AbsoluteIsolation(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AbsoluteIsolation*)
   {
      ::AbsoluteIsolation *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::AbsoluteIsolation >(0);
      static ::ROOT::TGenericClassInfo 
         instance("AbsoluteIsolation", ::AbsoluteIsolation::Class_Version(), "./AbsoluteIsolation.h", 27,
                  typeid(::AbsoluteIsolation), DefineBehavior(ptr, ptr),
                  &::AbsoluteIsolation::Dictionary, isa_proxy, 4,
                  sizeof(::AbsoluteIsolation) );
      instance.SetNew(&new_AbsoluteIsolation);
      instance.SetNewArray(&newArray_AbsoluteIsolation);
      instance.SetDelete(&delete_AbsoluteIsolation);
      instance.SetDeleteArray(&deleteArray_AbsoluteIsolation);
      instance.SetDestructor(&destruct_AbsoluteIsolation);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AbsoluteIsolation*)
   {
      return GenerateInitInstanceLocal((::AbsoluteIsolation*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::AbsoluteIsolation*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
TClass *AbsoluteIsolation::fgIsA = 0;  // static to hold class pointer

//______________________________________________________________________________
const char *AbsoluteIsolation::Class_Name()
{
   return "AbsoluteIsolation";
}

//______________________________________________________________________________
const char *AbsoluteIsolation::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::AbsoluteIsolation*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int AbsoluteIsolation::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::AbsoluteIsolation*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
void AbsoluteIsolation::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::AbsoluteIsolation*)0x0)->GetClass();
}

//______________________________________________________________________________
TClass *AbsoluteIsolation::Class()
{
   if (!fgIsA) fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::AbsoluteIsolation*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
void AbsoluteIsolation::Streamer(TBuffer &R__b)
{
   // Stream an object of class AbsoluteIsolation.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(AbsoluteIsolation::Class(),this);
   } else {
      R__b.WriteClassBuffer(AbsoluteIsolation::Class(),this);
   }
}

//______________________________________________________________________________
void AbsoluteIsolation::ShowMembers(TMemberInspector &R__insp)
{
      // Inspect the data members of an object of class AbsoluteIsolation.
      TClass *R__cl = ::AbsoluteIsolation::IsA();
      if (R__cl || R__insp.IsA()) { }
      R__insp.Inspect(R__cl, R__insp.GetParent(), "fDeltaRMax", &fDeltaRMax);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "fPTRatioMax", &fPTRatioMax);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "*fClassifier", &fClassifier);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "*fFilter", &fFilter);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "*fItIsolationInputArray", &fItIsolationInputArray);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "*fItCandidateInputArray", &fItCandidateInputArray);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "*fIsolationInputArray", &fIsolationInputArray);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "*fCandidateInputArray", &fCandidateInputArray);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "*fRhoInputArray", &fRhoInputArray);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "*fOutputArray", &fOutputArray);
      DelphesModule::ShowMembers(R__insp);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_AbsoluteIsolation(void *p) {
      return  p ? new(p) ::AbsoluteIsolation : new ::AbsoluteIsolation;
   }
   static void *newArray_AbsoluteIsolation(Long_t nElements, void *p) {
      return p ? new(p) ::AbsoluteIsolation[nElements] : new ::AbsoluteIsolation[nElements];
   }
   // Wrapper around operator delete
   static void delete_AbsoluteIsolation(void *p) {
      delete ((::AbsoluteIsolation*)p);
   }
   static void deleteArray_AbsoluteIsolation(void *p) {
      delete [] ((::AbsoluteIsolation*)p);
   }
   static void destruct_AbsoluteIsolation(void *p) {
      typedef ::AbsoluteIsolation current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::AbsoluteIsolation

/********************************************************
* AbsoluteIsolation_dict.cc
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************/

#ifdef G__MEMTEST
#undef malloc
#undef free
#endif

#if defined(__GNUC__) && __GNUC__ >= 4 && ((__GNUC_MINOR__ == 2 && __GNUC_PATCHLEVEL__ >= 1) || (__GNUC_MINOR__ >= 3))
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif

extern "C" void G__cpp_reset_tagtableAbsoluteIsolation_dict();

extern "C" void G__set_cpp_environmentAbsoluteIsolation_dict() {
  G__add_compiledheader("TObject.h");
  G__add_compiledheader("TMemberInspector.h");
  G__add_compiledheader("AbsoluteIsolation.h");
  G__cpp_reset_tagtableAbsoluteIsolation_dict();
}
#include <new>
extern "C" int G__cpp_dllrevAbsoluteIsolation_dict() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* AbsoluteIsolation */
static int G__AbsoluteIsolation_dict_450_0_1(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   AbsoluteIsolation* p = NULL;
   char* gvp = (char*) G__getgvp();
   int n = G__getaryconstruct();
   if (n) {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new AbsoluteIsolation[n];
     } else {
       p = new((void*) gvp) AbsoluteIsolation[n];
     }
   } else {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new AbsoluteIsolation;
     } else {
       p = new((void*) gvp) AbsoluteIsolation;
     }
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_AbsoluteIsolation));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__AbsoluteIsolation_dict_450_0_5(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) AbsoluteIsolation::Class());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__AbsoluteIsolation_dict_450_0_6(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) AbsoluteIsolation::Class_Name());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__AbsoluteIsolation_dict_450_0_7(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 115, (long) AbsoluteIsolation::Class_Version());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__AbsoluteIsolation_dict_450_0_8(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      AbsoluteIsolation::Dictionary();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__AbsoluteIsolation_dict_450_0_12(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((AbsoluteIsolation*) G__getstructoffset())->StreamerNVirtual(*(TBuffer*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__AbsoluteIsolation_dict_450_0_13(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) AbsoluteIsolation::DeclFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__AbsoluteIsolation_dict_450_0_14(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) AbsoluteIsolation::ImplFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__AbsoluteIsolation_dict_450_0_15(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) AbsoluteIsolation::ImplFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__AbsoluteIsolation_dict_450_0_16(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) AbsoluteIsolation::DeclFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic copy constructor
static int G__AbsoluteIsolation_dict_450_0_17(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)

{
   AbsoluteIsolation* p;
   void* tmp = (void*) G__int(libp->para[0]);
   p = new AbsoluteIsolation(*(AbsoluteIsolation*) tmp);
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_AbsoluteIsolation));
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic destructor
typedef AbsoluteIsolation G__TAbsoluteIsolation;
static int G__AbsoluteIsolation_dict_450_0_18(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   char* gvp = (char*) G__getgvp();
   long soff = G__getstructoffset();
   int n = G__getaryconstruct();
   //
   //has_a_delete: 1
   //has_own_delete1arg: 0
   //has_own_delete2arg: 0
   //
   if (!soff) {
     return(1);
   }
   if (n) {
     if (gvp == (char*)G__PVOID) {
       delete[] (AbsoluteIsolation*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       for (int i = n - 1; i >= 0; --i) {
         ((AbsoluteIsolation*) (soff+(sizeof(AbsoluteIsolation)*i)))->~G__TAbsoluteIsolation();
       }
       G__setgvp((long)gvp);
     }
   } else {
     if (gvp == (char*)G__PVOID) {
       delete (AbsoluteIsolation*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       ((AbsoluteIsolation*) (soff))->~G__TAbsoluteIsolation();
       G__setgvp((long)gvp);
     }
   }
   G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}


/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/* AbsoluteIsolation */

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncAbsoluteIsolation_dict {
 public:
  G__Sizep2memfuncAbsoluteIsolation_dict(): p(&G__Sizep2memfuncAbsoluteIsolation_dict::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncAbsoluteIsolation_dict::*p)();
};

size_t G__get_sizep2memfuncAbsoluteIsolation_dict()
{
  G__Sizep2memfuncAbsoluteIsolation_dict a;
  G__setsizep2memfunc((int)a.sizep2memfunc());
  return((size_t)a.sizep2memfunc());
}


/*********************************************************
* virtual base class offset calculation interface
*********************************************************/

   /* Setting up class inheritance */

/*********************************************************
* Inheritance information setup/
*********************************************************/
extern "C" void G__cpp_setup_inheritanceAbsoluteIsolation_dict() {

   /* Setting up class inheritance */
   if(0==G__getnumbaseclass(G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_AbsoluteIsolation))) {
     AbsoluteIsolation *G__Lderived;
     G__Lderived=(AbsoluteIsolation*)0x1000;
     {
       DelphesModule *G__Lpbase=(DelphesModule*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_AbsoluteIsolation),G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_DelphesModule),(long)G__Lpbase-(long)G__Lderived,1,1);
     }
     {
       ExRootTask *G__Lpbase=(ExRootTask*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_AbsoluteIsolation),G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_ExRootTask),(long)G__Lpbase-(long)G__Lderived,1,0);
     }
     {
       TTask *G__Lpbase=(TTask*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_AbsoluteIsolation),G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_TTask),(long)G__Lpbase-(long)G__Lderived,1,0);
     }
     {
       TNamed *G__Lpbase=(TNamed*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_AbsoluteIsolation),G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_TNamed),(long)G__Lpbase-(long)G__Lderived,1,0);
     }
     {
       TObject *G__Lpbase=(TObject*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_AbsoluteIsolation),G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_TObject),(long)G__Lpbase-(long)G__Lderived,1,0);
     }
   }
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetableAbsoluteIsolation_dict() {

   /* Setting up typedef entry */
   G__search_typename2("Version_t",115,-1,0,-1);
   G__setnewtype(-1,"Class version identifier (short)",0);
   G__search_typename2("vector<ROOT::TSchemaHelper>",117,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<TVirtualArray*>",117,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<std::bidirectional_iterator_tag,TObject*,std::ptrdiff_t,const TObject**,const TObject*&>",117,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*,std::ptrdiff_t,const TObject**,const TObject*&>",117,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*>",117,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*,long>",117,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*,long,const TObject**>",117,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("map<TString,TString>",117,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_maplETStringcOTStringcOlesslETStringgRcOallocatorlEpairlEconstsPTStringcOTStringgRsPgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("map<TString,TString,less<TString> >",117,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_maplETStringcOTStringcOlesslETStringgRcOallocatorlEpairlEconstsPTStringcOTStringgRsPgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */

   /* AbsoluteIsolation */
static void G__setup_memvarAbsoluteIsolation(void) {
   G__tag_memvar_setup(G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_AbsoluteIsolation));
   { AbsoluteIsolation *p; p=(AbsoluteIsolation*)0x1000; if (p) { }
   G__memvar_setup((void*)0,100,0,0,-1,G__defined_typename("Double_t"),-1,4,"fDeltaRMax=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,0,-1,G__defined_typename("Double_t"),-1,4,"fPTRatioMax=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_AbsoluteIsolationClassifier),-1,-1,4,"fClassifier=",0,"!");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_ExRootFilter),-1,-1,4,"fFilter=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_TIterator),-1,-1,4,"fItIsolationInputArray=",0,"!");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_TIterator),-1,-1,4,"fItCandidateInputArray=",0,"!");
   G__memvar_setup((void*)0,85,0,1,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_TObjArray),-1,-1,4,"fIsolationInputArray=",0,"!");
   G__memvar_setup((void*)0,85,0,1,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_TObjArray),-1,-1,4,"fCandidateInputArray=",0,"!");
   G__memvar_setup((void*)0,85,0,1,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_TObjArray),-1,-1,4,"fRhoInputArray=",0,"!");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_TObjArray),-1,-1,4,"fOutputArray=",0,"!");
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_TClass),-1,-2,4,"fgIsA=",0,(char*)NULL);
   }
   G__tag_memvar_reset();
}

extern "C" void G__cpp_setup_memvarAbsoluteIsolation_dict() {
}
/***********************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
***********************************************************/

/*********************************************************
* Member function information setup for each class
*********************************************************/
static void G__setup_memfuncAbsoluteIsolation(void) {
   /* AbsoluteIsolation */
   G__tag_memfunc_setup(G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_AbsoluteIsolation));
   G__memfunc_setup("AbsoluteIsolation",1777,G__AbsoluteIsolation_dict_450_0_1, 105, G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_AbsoluteIsolation), -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Init",404,(G__InterfaceMethod) NULL,121, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Process",735,(G__InterfaceMethod) NULL,121, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Finish",609,(G__InterfaceMethod) NULL,121, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Class",502,G__AbsoluteIsolation_dict_450_0_5, 85, G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_TClass), -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (TClass* (*)())(&AbsoluteIsolation::Class) ), 0);
   G__memfunc_setup("Class_Name",982,G__AbsoluteIsolation_dict_450_0_6, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&AbsoluteIsolation::Class_Name) ), 0);
   G__memfunc_setup("Class_Version",1339,G__AbsoluteIsolation_dict_450_0_7, 115, -1, G__defined_typename("Version_t"), 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (Version_t (*)())(&AbsoluteIsolation::Class_Version) ), 0);
   G__memfunc_setup("Dictionary",1046,G__AbsoluteIsolation_dict_450_0_8, 121, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (void (*)())(&AbsoluteIsolation::Dictionary) ), 0);
   G__memfunc_setup("IsA",253,(G__InterfaceMethod) NULL,85, G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_TClass), -1, 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("ShowMembers",1132,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "u 'TMemberInspector' - 1 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Streamer",835,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("StreamerNVirtual",1656,G__AbsoluteIsolation_dict_450_0_12, 121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - ClassDef_StreamerNVirtual_b", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("DeclFileName",1145,G__AbsoluteIsolation_dict_450_0_13, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&AbsoluteIsolation::DeclFileName) ), 0);
   G__memfunc_setup("ImplFileLine",1178,G__AbsoluteIsolation_dict_450_0_14, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (int (*)())(&AbsoluteIsolation::ImplFileLine) ), 0);
   G__memfunc_setup("ImplFileName",1171,G__AbsoluteIsolation_dict_450_0_15, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&AbsoluteIsolation::ImplFileName) ), 0);
   G__memfunc_setup("DeclFileLine",1152,G__AbsoluteIsolation_dict_450_0_16, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (int (*)())(&AbsoluteIsolation::DeclFileLine) ), 0);
   // automatic copy constructor
   G__memfunc_setup("AbsoluteIsolation", 1777, G__AbsoluteIsolation_dict_450_0_17, (int) ('i'), G__get_linked_tagnum(&G__AbsoluteIsolation_dictLN_AbsoluteIsolation), -1, 0, 1, 1, 1, 0, "u 'AbsoluteIsolation' - 11 - -", (char*) NULL, (void*) NULL, 0);
   // automatic destructor
   G__memfunc_setup("~AbsoluteIsolation", 1903, G__AbsoluteIsolation_dict_450_0_18, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 1);
   G__tag_memfunc_reset();
}


/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncAbsoluteIsolation_dict() {
}

/*********************************************************
* Global variable information setup for each class
*********************************************************/
static void G__cpp_setup_global0() {

   /* Setting up global variables */
   G__resetplocal();

}

static void G__cpp_setup_global1() {

   G__resetglobalenv();
}
extern "C" void G__cpp_setup_globalAbsoluteIsolation_dict() {
  G__cpp_setup_global0();
  G__cpp_setup_global1();
}

/*********************************************************
* Global function information setup for each class
*********************************************************/
static void G__cpp_setup_func0() {
   G__lastifuncposition();

}

static void G__cpp_setup_func1() {
}

static void G__cpp_setup_func2() {
}

static void G__cpp_setup_func3() {
}

static void G__cpp_setup_func4() {
}

static void G__cpp_setup_func5() {
}

static void G__cpp_setup_func6() {
}

static void G__cpp_setup_func7() {
}

static void G__cpp_setup_func8() {
}

static void G__cpp_setup_func9() {
}

static void G__cpp_setup_func10() {
}

static void G__cpp_setup_func11() {
}

static void G__cpp_setup_func12() {
}

static void G__cpp_setup_func13() {
}

static void G__cpp_setup_func14() {
}

static void G__cpp_setup_func15() {
}

static void G__cpp_setup_func16() {
}

static void G__cpp_setup_func17() {

   G__resetifuncposition();
}

extern "C" void G__cpp_setup_funcAbsoluteIsolation_dict() {
  G__cpp_setup_func0();
  G__cpp_setup_func1();
  G__cpp_setup_func2();
  G__cpp_setup_func3();
  G__cpp_setup_func4();
  G__cpp_setup_func5();
  G__cpp_setup_func6();
  G__cpp_setup_func7();
  G__cpp_setup_func8();
  G__cpp_setup_func9();
  G__cpp_setup_func10();
  G__cpp_setup_func11();
  G__cpp_setup_func12();
  G__cpp_setup_func13();
  G__cpp_setup_func14();
  G__cpp_setup_func15();
  G__cpp_setup_func16();
  G__cpp_setup_func17();
}

/*********************************************************
* Class,struct,union,enum tag information setup
*********************************************************/
/* Setup class/struct taginfo */
G__linked_taginfo G__AbsoluteIsolation_dictLN_TClass = { "TClass" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_TBuffer = { "TBuffer" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_TMemberInspector = { "TMemberInspector" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_TObject = { "TObject" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_TNamed = { "TNamed" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR = { "vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR = { "reverse_iterator<vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >::iterator>" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_TObjArray = { "TObjArray" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR = { "vector<TVirtualArray*,allocator<TVirtualArray*> >" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<TVirtualArray*,allocator<TVirtualArray*> >::iterator>" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_TIterator = { "TIterator" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR = { "iterator<bidirectional_iterator_tag,TObject*,long,const TObject**,const TObject*&>" , 115 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_TTask = { "TTask" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_maplETStringcOTStringcOlesslETStringgRcOallocatorlEpairlEconstsPTStringcOTStringgRsPgRsPgR = { "map<TString,TString,less<TString>,allocator<pair<const TString,TString> > >" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_ExRootTask = { "ExRootTask" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_DelphesModule = { "DelphesModule" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_ExRootFilter = { "ExRootFilter" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_AbsoluteIsolationClassifier = { "AbsoluteIsolationClassifier" , 99 , -1 };
G__linked_taginfo G__AbsoluteIsolation_dictLN_AbsoluteIsolation = { "AbsoluteIsolation" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtableAbsoluteIsolation_dict() {
  G__AbsoluteIsolation_dictLN_TClass.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_TBuffer.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_TMemberInspector.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_TObject.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_TNamed.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_TObjArray.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_TIterator.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_TTask.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_maplETStringcOTStringcOlesslETStringgRcOallocatorlEpairlEconstsPTStringcOTStringgRsPgRsPgR.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_ExRootTask.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_DelphesModule.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_ExRootFilter.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_AbsoluteIsolationClassifier.tagnum = -1 ;
  G__AbsoluteIsolation_dictLN_AbsoluteIsolation.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtableAbsoluteIsolation_dict() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_TClass);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_TBuffer);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_TMemberInspector);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_TObject);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_TNamed);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_TObjArray);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_TIterator);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_TTask);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_maplETStringcOTStringcOlesslETStringgRcOallocatorlEpairlEconstsPTStringcOTStringgRsPgRsPgR);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_ExRootTask);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_DelphesModule);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_ExRootFilter);
   G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_AbsoluteIsolationClassifier);
   G__tagtable_setup(G__get_linked_tagnum_fwd(&G__AbsoluteIsolation_dictLN_AbsoluteIsolation),sizeof(AbsoluteIsolation),-1,324864,(char*)NULL,G__setup_memvarAbsoluteIsolation,G__setup_memfuncAbsoluteIsolation);
}
extern "C" void G__cpp_setupAbsoluteIsolation_dict(void) {
  G__check_setup_version(30051515,"G__cpp_setupAbsoluteIsolation_dict()");
  G__set_cpp_environmentAbsoluteIsolation_dict();
  G__cpp_setup_tagtableAbsoluteIsolation_dict();

  G__cpp_setup_inheritanceAbsoluteIsolation_dict();

  G__cpp_setup_typetableAbsoluteIsolation_dict();

  G__cpp_setup_memvarAbsoluteIsolation_dict();

  G__cpp_setup_memfuncAbsoluteIsolation_dict();
  G__cpp_setup_globalAbsoluteIsolation_dict();
  G__cpp_setup_funcAbsoluteIsolation_dict();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncAbsoluteIsolation_dict();
  return;
}
class G__cpp_setup_initAbsoluteIsolation_dict {
  public:
    G__cpp_setup_initAbsoluteIsolation_dict() { G__add_setup_func("AbsoluteIsolation_dict",(G__incsetup)(&G__cpp_setupAbsoluteIsolation_dict)); G__call_setup_funcs(); }
   ~G__cpp_setup_initAbsoluteIsolation_dict() { G__remove_setup_func("AbsoluteIsolation_dict"); }
};
G__cpp_setup_initAbsoluteIsolation_dict G__cpp_setup_initializerAbsoluteIsolation_dict;

