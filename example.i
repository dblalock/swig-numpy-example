%module example

// include files that SWIG will need to see
%{
    #define SWIG_FILE_WITH_INIT
    #include <vector>
    #include "src/include/public_interface.hpp"
    #include "src/include/public_interface_eigen.hpp"
%}

// include other SWIG interface files
%include <config.i>

// tell SWIG to wrap the relevant files
%include "src/include/public_interface.hpp"
%include "src/include/public_interface_eigen.hpp"

// instantiate templates; note that these must be *after* the appropriate %include
// NOTE: this doesn't seem to work with our custom "apply"s above, so I don't think
// templates and numpy really play together nicely. The moral appears to be that
// one should use the templates internally to avoid duplicate code and thinly wrap
// them in type-specific classes/functions in the headers
// %template(addArrays_int) template_add_arrays<int>;
// %template(addArrays_dbl) template_add_arrays<double>;
