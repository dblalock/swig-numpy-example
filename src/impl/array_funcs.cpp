/** @file
 *
 * Array functions
 *
 * A handful of functions to be wrapped in python
 */

#ifndef ARRAYFUNCS_CPP
#define ARRAYFUNCS_CPP

#include <vector>
#include <string.h>

#include "public_interface.hpp"
// #include "public_interface.hpp"

void inplace(double *invec, int n) {
    for (int i=0; i<n; i++) {
        invec[i] = 2*invec[i];
    }
}

void range(int *outVec, int len, int step) {
// void range(int step, int *outVec, int len) {
	int val = 0;
    for (int i=0; i < len; i++) {
        outVec[i] = val;
        val += step;
    }
}

double sumOfArrays(double* inVec1, int len1, double* inVec2, int len2) {
	double sum = 0;
	for (int i=0; i< len1; i++) {
        sum += inVec1[i] + inVec2[i];
    }
    return sum;
}

void timesTwo(double* inVec, int len, double* outVec, int outLen) {
// void timesTwo(double* inVec, int len, double* outVec) {
	for (int i=0; i<len; i++) {
        outVec[i] = 2*inVec[i];
    }
}

void addArrays(double* inVec1, int len1, double* inVec2, int len2, double* outVec, int len) {
    for (int i=0; i< len; i++) {
        outVec[i] = inVec1[i] + inVec2[i];
    }
}

// template <typename T>
// void template_add_arrays(T* v1, int len1, T* v2, int len2, T* outVec, int len) {
// 	for (int i=0; i< len; i++) {
//         outVec[i] = inVec1[i] + inVec2[i];
//     }
// }

// int array_read_func(const double* ar, int len) {
// 	double sum = 0;
// 	for(unsigned i = 0; i < len; ++i) {
// 		sum += ar[i];
// 	}
// 	return sum;
// }

// void array_modify_func(double* ar, int len) {
// 	for(unsigned i = 1; i < len; ++i) {
// 		ar[i] += ar[i-1];
// 	}
// }

// template<typename T>
// T template_array_read_func(const T* ar, int len) {
// 	T sum = 0;
// 	for(unsigned i = 0; i < len; ++i) {
// 		sum += ar[i];
// 	}
// 	return sum;
// }

// template<typename T>
// class ArrayUser {
// private:
// 	std::vector<T> _array;
// 	T _scaleBy;
// public:
// 	ArrayUser(T scaleBy);
// 	virtual ~ArrayUser();
// 	void setArray(const T* ar, int len);
// 	void getArray(T* outVec, int len);
// };

// template <typename T> ArrayUser<T>::ArrayUser(T scaleBy):
// 	_scaleBy(scaleBy)
// {}

// template <typename T>
// void ArrayUser<T>::setArray(const T* ar, int len) {
// 	_array.clear();
// 	for (int i = 0; i < len; i++) {
// 		_array.push_back(ar[i] * _scaleBy);
// 	}
// 	// _array.assign(ar, ar+len);	// more efficient, but doesn't scaleBy
// }

// template <typename T>
// void ArrayUser<T>::getArray(T* outVec, int len) {
// 	memcpy(outVec, &_array[0], sizeof(T)*len);
// }

// ArrayUser_dbl::ArrayUser_dbl(double scaleBy):
// 	_pimpl(new ArrayUser<double>(scaleBy))
// { }

// ArrayUser_dbl::~ArrayUser_dbl() {
// 	delete _pimpl;
// }

// void ArrayUser_dbl::setArray(const double* ar, int len) {
// 	_pimpl->setArray(ar,len);
// }

// void ArrayUser_dbl::getArray(double* outVec, int len) {
// 	_pimpl->getArray(outVec,len);
// }


 #endif // ARRAYFUNCS_CPP
 