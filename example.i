%module example

%{
    #define SWIG_FILE_WITH_INIT
    #include <vector>
    #include "src/include/public_interface.hpp"
    #include "src/include/public_interface_eigen.hpp"
%}

%include "numpy.i"
%init %{
    import_array();
%}
%include <eigen.i>

// ------------------------------------------------
// vector typemaps
// ------------------------------------------------

%define %np_vector_typemaps(DTYPE, NPY_DPTYE)

namespace std {
	// hmm...apparently telling SWIG to try to optimize this breaks it
	// %typemap(out, fragment="NumPy_Fragments", optimal="1") vector<DTYPE> {
	%typemap(out, fragment="NumPy_Fragments") vector<DTYPE> {
		// create python array of appropriate shape
	 	npy_intp sz = static_cast<npy_intp>($1.size());
	 	npy_intp dims[] = {sz};
	 	PyObject* out_array = PyArray_SimpleNew(1, dims, NPY_DPTYE);

		if (! out_array) {
		    PyErr_SetString(PyExc_ValueError,
		                    "vector wrap: unable to create the output array.");
		    return NULL;
		}

		// copy data from vect into numpy array
		DTYPE* out_data = (DTYPE*) array_data(out_array);
		for (size_t i = 0; i < sz; i++) {
			out_data[i] = static_cast<DTYPE>($1[i]);
		}

		$result = out_array;
	}
}

%enddef

%np_vector_typemaps(int, NPY_INT)
%np_vector_typemaps(long, NPY_LONG)
%np_vector_typemaps(float, NPY_FLOAT)
%np_vector_typemaps(double, NPY_DOUBLE)
// %np_vector_typemaps(SimpleStruct*, NPY_OBJECT) // breaks

// ------------------------------------------------
// eigen typemaps
// ------------------------------------------------

%eigen_typemaps(MatrixXd)
%eigen_typemaps(VectorXd)
// %eigen_typemaps(ArrayXd)
%eigen_typemaps(MatrixXf)
%eigen_typemaps(VectorXf)
%eigen_typemaps(MatrixXi)
%eigen_typemaps(VectorXi)

// ------------------------------------------------
// raw c array typemaps
// ------------------------------------------------

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
%include "src/include/public_interface_eigen.hpp"

// instantiate templates; note that these must be *after* the appropriate %include
// NOTE: this doesn't seem to work with our custom "apply"s above, so I don't think
// templates and numpy really play together nicely. The moral appears to be that
// one should use the templates internally to avoid duplicate code and thinly wrap
// them in type-specific classes/functions in the headers
// %template(addArrays_int) template_add_arrays<int>;
// %template(addArrays_dbl) template_add_arrays<double>;
