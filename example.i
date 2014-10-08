%module example

%{
    #define SWIG_FILE_WITH_INIT
    #include "src/include/public_interface.hpp"
%}

%include "numpy.i"

%init %{
    import_array();
%}

%apply (double* INPLACE_ARRAY1, int DIM1) {(double* invec, int n)}
%include "src/include/public_interface.hpp"

