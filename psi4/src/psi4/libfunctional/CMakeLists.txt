set(sources_list PBE_Cfunctional.cc 
                 PZ81_Cfunctional.cc 
                 PW91_Cfunctional.cc 
                 wpbec_functional.cc 
                 VWN3_Cfunctional.cc 
                 superfunctional.cc 
                 LYP_Cfunctional.cc 
                 FT97B_Xfunctional.cc 
                 wpbex_functional.cc 
                 FT97_Cfunctional.cc 
                 VWN5_Cfunctional.cc 
                 PW92_Cfunctional.cc 
                 P86_Cfunctional.cc 
                 cfunctional.cc 
                 factory.cc 
                 utility.cc 
                 functional.cc 
                 xfunctional.cc 
)
psi4_add_module(lib functional sources_list disp)
