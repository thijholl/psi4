#ifndef SCF_DF_H
#define SCF_DF_H
#include <psi4-dec.h>

using namespace psi;

namespace psi {

class BasisSet;
class Matrix;
class Options;
class FittingMetric;
class SchwarzSieve;
class TwoBodyAOInt;
class PSIO;

namespace scf {

class DFHF {
    
    protected:
        // Is this disk or core?
        bool is_disk_;
        // Is this object RI-J or RI-JK?
        bool is_jk_;
        // Is this object initialized?
        bool is_initialized_;
        // Whether the alpha and beta orbitals are equal or not
        bool restricted_;
        // The psio object
        shared_ptr<PSIO> psio_;
        // Inverse of fitting metric  
        shared_ptr<FittingMetric> Jinv_;
        // The three index tensor (or a chunk if on disk)
        shared_ptr<Matrix> Qmn_;
        // Shared pointer to alpha density matrix
        shared_ptr<Matrix> Da_;
        // Shared pointer to beta density matrix
        shared_ptr<Matrix> Db_;
        // Shared pointer to alpha occupation matrix
        shared_ptr<Matrix> Ca_;
        // Shared pointer to beta occupation matrix
        shared_ptr<Matrix> Cb_;
        // Shared pointer to total Coulomb matrix
        shared_ptr<Matrix> Ja_;
        // Shared pointer to alpha Exchange matrix
        shared_ptr<Matrix> Ka_;
        // Shared pointer to beta Exchange matrix
        shared_ptr<Matrix> Kb_;
        // Number of alpha electrons
        const int* nalpha_;
        // Number of beta electrons
        const int* nbeta_;
        // Constant reference to the options object
        Options& options_;
        // Zero basis set
        shared_ptr<BasisSet> zero_;
        // Primary basis set
        shared_ptr<BasisSet> primary_;
        // Auxiliary basis set 
        shared_ptr<BasisSet> auxiliary_;
        // Schwarz Sieve object 
        shared_ptr<SchwarzSieve> schwarz_;

        // memory in doubles
        unsigned long int memory_;
    
        // Helper methods
        void form_J_DF_RHF();
        void form_J_DF_UHF();
        void form_JK_DF_RHF();
        void form_JK_DF_UHF();

        // Initialize methods
        void initialize();
        void initialize_JK_disk();
        void initialize_JK_core();
        void initialize_J_disk();
        void initialize_J_core();

        // Block methods
        void compute_JK_block(shared_ptr<Matrix> Qmn, int nrows);
        void compute_J_core();

    public:
        // Constructor for generic HF, with J, K, D to be set later
        DFHF(shared_ptr<BasisSet> basis, shared_ptr<PSIO> psio, Options& opt);
        // Destructor
        ~DFHF();
        // Setup 
        void common_init();
        
        // Setter methods, to be called from the JK functors
        void set_jk(bool jk) { is_jk_ = jk; }
        void set_restricted(bool y_n) { restricted_ = y_n; }
        void set_J(shared_ptr<Matrix> Ja) {Ja_ = Ja;}
        void set_Ka(shared_ptr<Matrix> Ka) {Ka_ = Ka;}
        void set_Kb(shared_ptr<Matrix> Kb) {Kb_ = Kb;}
        void set_Da(shared_ptr<Matrix> Da) {Da_ = Da;}
        void set_Db(shared_ptr<Matrix> Db) {Db_ = Db;}
        void set_Ca(shared_ptr<Matrix> Ca) {Ca_ = Ca;}
        void set_Cb(shared_ptr<Matrix> Cb) {Cb_ = Cb;}
        void set_Na(const int* Na) {nalpha_ = Na;}
        void set_Nb(const int* Nb) {nbeta_ = Nb;}
        // form J and K
        void form_J_DF() { restricted_ ? form_J_DF_RHF() : form_J_DF_UHF(); }
        void form_JK_DF() { restricted_ ? form_JK_DF_RHF() : form_JK_DF_UHF(); }

};

}}

#endif
