#include <boost/python.hpp>

#include <cstdlib>
#include <cstdio>
#include <string>

#include <psifiles.h>
#include <libciomr/libciomr.h>
#include <libpsio/psio.h>
#include <libchkpt/chkpt.h>
#include <libpsio/psio.hpp>
#include <libparallel/parallel.h>
#include <libchkpt/chkpt.hpp>
#include <libiwl/iwl.h>
#include <libqt/qt.h>

#include <libmints/mints.h>
#include <psi4-dec.h>

#include <liblmp2_solver/lmp2.h>

using namespace boost;
using namespace std;

namespace psi { namespace lmp2 {

PsiReturnType lmp2(Options & options)
{
    tstart();

    boost::shared_ptr<PSIO> psio = PSIO::shared_object();

    // Initialize the psi3 timer library.
    timer_init();

    string reference = options.get_str("REFERENCE");
    boost::shared_ptr<Wavefunction> lmp2;
    double energy;

    if (reference == "RHF") {
        lmp2 = boost::shared_ptr<Wavefunction>(new LMP2(options, psio));
    }
    else {
        throw InputException("Unknown reference " + reference, "REFERENCE", __FILE__, __LINE__);
        energy = 0.0;
    }

    energy = lmp2->compute_energy();

    // Set some environment variables
    Process::environment.globals["LMP2 ENERGY"] = energy;
    Process::environment.globals["CURRENT ENERGY"] = energy;

    // Shut down psi.
    timer_done();

    tstop();

    return Success;
}

}}
