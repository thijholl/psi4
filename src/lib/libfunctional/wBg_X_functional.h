#ifndef wBg_X_functional_h
#define wBg_X_functional_h
/**********************************************************
* wBg_X_functional.h: declarations for wBg_X_functional for KS-DFT
* Robert Parrish, robparrish@gmail.com
* Autogenerated by MATLAB Script on 08-Mar-2012
*
***********************************************************/
#include "functional.h"

namespace psi { namespace functional {

class wBg_X_Functional : public Functional {
public:
    wBg_X_Functional(int npoints, int deriv);
    virtual ~wBg_X_Functional();
    virtual void computeRKSFunctional(boost::shared_ptr<RKSFunctions> prop);
    virtual void computeUKSFunctional(boost::shared_ptr<UKSFunctions> prop);
};
}}
#endif

