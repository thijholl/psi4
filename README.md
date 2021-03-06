Psi4: Open-Source Quantum Chemistry
-----------------------------------

Psi4 is an open-source suite of *ab initio* quantum chemistry programs
designed for efficient, high-accuracy simulations of a variety of
molecular properties. We can routinely perform computations with more
than 2500 basis functions running serially or on multi-core machines.

With computationally demanding portions written in C++, Pybind11 exports
many of the C++ classes into Python, and a flexible Python driver, Psi4
strives to be friendly to both users and developers.

* **Users' Website**  www.psicode.org

* **Downloading and Installing Psi4** https://github.com/psi4/psi4/wiki

* **Manual**  [http://bit.ly/psi4manual](http://psicode.org/psi4manual/master/index.html) (built nightly from master branch)

* **Tutorial** http://psicode.org/psi4manual/master/tutorial.html

* **Forum** http://forum.psicode.org

* **Communication & Support** http://psicode.org/psi4manual/master/introduction.html#technical-support

* **Public Github**  https://github.com/psi4/psi4 (authoritative repository)

* **Private Github**  https://github.com/psi4/psi4private (scheduled to become read-only mirror of public GitHub master)

* **Travis CI build status** [![Build Status](https://travis-ci.org/psi4/psi4.svg?branch=master)](https://travis-ci.org/psi4/psi4)

* **Anaconda**  https://anaconda.org/psi4 (binary available for Linux [![Binstar Badge](https://anaconda.org/psi4/psi4/badges/downloads.svg)](https://anaconda.org/psi4/psi4) ) [instructions](http://psicode.org/psi4manual/master/conda.html#quick-installation)

* **Interested Developers**  http://psicode.org/developers.php (welcome to fork psi4/psi4 or store private branches at psi4/psi4private)

* **Sample Inputs**  http://www.psicode.org/psi4manual/master/testsuite.html (also in share/psi4/samples)

* **Download Tarball** https://github.com/psi4/psi4/releases 

* **Build Dashboard** https://testboard.org/cdash/index.php?project=Psi

* **YouTube Channel** https://www.youtube.com/psitutorials

Installation Instructions
-------------------------

With the newest CMake rewrite there are three steps: configuration, build, and install.  After obtaining the source, in the top-level directory do the following:

1. Configure
   - Done through CMake.  Care has been taken to support canonical CMake variables so for finer tuning consult the CMake documentation or consider using the GUI that comes with CMake (and will display all variables).
   - Command will look something like:
   ~~~{.sh}
   cmake -Bbuild -D<CMAKE_VARIABLE_ONE>=<VALUE_ONE> ...
   ~~~
      - The `-Bbuild` sets the build directory to a directory called `build`
      - The `-D<CMAKE_VARIABLE_ONE>` says set the variable to the given value
      - The ellipses signify the possible addition of more variables. These include:
       - `CMAKE_INSTALL_PREFIX` Where to install Psi4.
       - `CMAKE_C_COMPILER` The C compiler.
       - `CMAKE_CXX_COMPILER` The C++ compiler.
       - `CMAKE_Fortran_COMPILER` The Fortran compiler. Psi4 does not contain Fortran, but some external modules do.
       - `CMAKE_C_FLAGS` Any extra C flags you want to pass.
       - `CMAKE_CXX_FLAGS` Any extra C++ flags you want to pass.
       - `CMAKE_Fortran_FLAGS` Any extra Fortran flags you want to pass.
       - `CMAKE_BUILD_TYPE` Is this Debug, Release, or RelWithDebInfo.
       - `CMAKE_PREFIX_PATH` List of places `find_package` should look for packages that have been configured with CMake.
       - `PYTHON_EXECUTABLE` Path to the python executable you want to use.
       - `PYTHON_LIBRARY` Path to the python library that goes with the exe.
       - `PYTHON_INCLUDE_DIR` Path to the python include files.
       - `ENABLE_PCMSOLVER` On means build PCMSolver library (requires Fortran).
       - `ENABLE_CHEMPS2`   Enables chemps2 library for DMRG.
       - `ENABLE_DKH` Enables relativistic DKH integrals (requires Fortran).
       - `ENABLE_LIBERD` Enables ERD library in addition to libint (requires Fortran).
       - `ENABLE_GDMA` Enables Stone's GDMA multipole code (requires Fortran).
       - `ENABLE_AMBIT` Enables the Ambit tensor library.
       - `MAX_AM_ERI` The maximum angular momentum for libint.

2.  Build
    - After you ran the configure command, and it ran successfully, change to the build directory and run:
    ~~~{.sh}
    # n is the number of cores to use for building
    make -j n
    ~~~

3. (Optional) Test
    - You may test your installation by invoking in the build directory:
    ~~~{.sh}
    # Runs a very minimal set of tests.  Omit the -Rtu for all tests
    ctest -Rtu
    ~~~

4.  Install
    - Psi4 must be installed.  From the build directory:
    ~~~{.sh}
    make install
    ~~~
