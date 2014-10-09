%module example

%{
    #define SWIG_FILE_WITH_INIT
    #include "src/include/public_interface.hpp"
%}

%include "numpy.i"
%init %{
    import_array();
%}

// apply numpy typemaps based on arg types + names
%apply (double* INPLACE_ARRAY1, int DIM1) {(double* inVec, int len)};

%apply (double* IN_ARRAY1, int DIM1) {(double* v, int len)};
%apply (double* IN_ARRAY1, int DIM1) {(double* ar, int len)};
%apply (const double* IN_ARRAY1, int DIM1) {(const double* ar, int len)};
%apply (double* IN_ARRAY1, int DIM1) {(double* v, int inLen)};
%apply (double* IN_ARRAY1, int DIM1) {(double* v1, int len1)};
%apply (double* IN_ARRAY1, int DIM1) {(double* v2, int len2)};

%apply (int* ARGOUT_ARRAY1, int DIM1) {(int* outVec, int len)};
%apply (int* ARGOUT_ARRAY1, int DIM1) {(int* outVec, int outLen)};
%apply (double* ARGOUT_ARRAY1, int DIM1) {(double* outVec, int len)};
%apply (double* ARGOUT_ARRAY1, int DIM1) {(double* outVec, int outLen)};
// %apply (int DIM1, double* ARGOUT_ARRAY1) {(int len, double* outVec)};

%include "src/include/public_interface.hpp"

// instantiate templates; note that these must be *after* the appropriate %include
// NOTE: this doesn't seem to work with our custom "apply"s above, so I don't think
// templates and numpy really play together nicely. The moral appears to be that
// one should use the templates internally to avoid duplicate code and thinly wrap
// them in type-specific classes/functions in the headers
// %template(addArrays_int) template_add_arrays<int>;
// %template(addArrays_dbl) template_add_arrays<double>;