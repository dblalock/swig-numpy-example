%module example

%{
    #define SWIG_FILE_WITH_INIT
    #include "src/include/public_interface.hpp"
    // #include "src/utils/util.h"
    #include "src/impl/util.h"
%}

%include "numpy.i"
%init %{
    import_array();
%}

%apply (double* INPLACE_ARRAY1, int DIM1) {(double* invec, int n)}
%include "src/include/public_interface.hpp"

