

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
%eigen_typemaps(ArrayXXd)
%eigen_typemaps(ArrayXd)

%eigen_typemaps(MatrixXf)
%eigen_typemaps(VectorXf)
%eigen_typemaps(ArrayXXf)
%eigen_typemaps(ArrayXf)

%eigen_typemaps(MatrixXi)
%eigen_typemaps(VectorXi)
%eigen_typemaps(ArrayXXi)
%eigen_typemaps(ArrayXi)

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
