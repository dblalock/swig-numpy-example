
#ifndef PUBLIC_INTERFACE_HPP
#define PUBLIC_INTERFACE_HPP

#include <vector>

/** Sanity check function to print out a string using printf */
void printStuff();

/** Simple function to modify an array in-place by doubling its elements */
void inplace(double *inVec, int len);

/** Return an array; equivalent to built-in range(n) */
void range(int *outVec, int len, int step);	//hmm...both of these work if we call them right
// void range(int step, int *outVec, int len);

/** Read in two arrays; return the sum of the elements in both */
double sumOfArrays(double* v1, int len1, double* v2, int len2);

/** Read in an array and return another one (equal to twice the input) */
// void timesTwo(double* v, int inLen, double* outVec, int outLen);
void timesTwo(double* v, int len, double* outVec, int outLen);

/** Add two arrays together and return an array */
void addArrays(double* v1, int len1, double* v2, int len2, double* outVec, int len);

/** A function that operates on a read-only array
 * @return The sum of the elements in the array */
// int array_read_func(const double* ar, int len);

/** A function that modifies an array in-place. Specifically, sets
 * each element to the cumulative sum of all elements so far, starting
 * at index 0. */
// void array_modify_func(double* ar, int len);

/** A templated function that operates on a read-only array
 * @return The sum of the elements in the array */
// template <typename T>
// T template_array_read_func(const T* ar, int len);

// template <typename T>
// void template_add_arrays(T* v1, int len1, T* v2, int len2, T* outVec, int len);
template <typename T>
void template_add_arrays(T* v1, int len1, T* v2, int len2, T* outVec, int len) {
	for (int i=0; i< len; i++) {
        outVec[i] = v1[i] + v2[i];
    }
}

class SimpleClass {
private:
	int _n;
public:
	SimpleClass(int n): _n(n) {}
	// ~SimpleClass();	// NOTE: if you uncomment this, you'll get linking errors
	int get_n() {
		return _n;
	}
};

// forward declare template class
// template <typename T> class ArrayUser;

// declare type-specific class that uses it (via pimpl idiom)
// class ArrayUser_dbl {
// private:
// 	ArrayUser<double> *_pimpl;
// public:
// 	ArrayUser_dbl(double scaleBy);
// 	~ArrayUser_dbl();
// 	void setArray(const double* ar, int len);
// 	void getArray(double* outVec, int len);
// };


#endif // PUBLIC_INTERFACE_HPP
