/** @file
 *
 * Array functions
 *
 * A handful of functions to be wrapped in python
 */

#ifndef ARRAYFUNCS_CPP
#define ARRAYFUNCS_CPP

#include <vector>

#include "public_interface.hpp"
// #include "public_interface.hpp"

int array_read_func(const double* ar, int len) {
	double sum = 0;
	for(unsigned i = 0; i < len; ++i) {
		sum += ar[i];
	}
	return sum;
}

void array_modify_func(double* ar, int len) {
	for(unsigned i = 1; i < len; ++i) {
		ar[i] += ar[i-1];
	}
}

template<typename T>
T template_array_read_func(const T* ar, int len) {
	T sum = 0;
	for(unsigned i = 0; i < len; ++i) {
		sum += ar[i];
	}
	return sum;
}

void ArrayUser::setArray(const double* ar, int len) {
	_array.assign(ar, ar+len);
}

template <typename T>
void TemplatedArrayUser<T>::setArray(const T* ar, int len) {
	_array.assign(ar, ar+len);
}

 #endif // ARRAYFUNCS_CPP
 