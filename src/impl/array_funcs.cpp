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

// -------------------------------------------------------------- Functions

void inplace(double *invec, int n) {
    for (int i=0; i<n; i++) {
        invec[i] = 2*invec[i];
    }
}

void range(int *outVec, int len, int step) {
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
	for (int i=0; i<len; i++) {
        outVec[i] = 2*inVec[i];
    }
}

void addArrays(double* inVec1, int len1, double* inVec2, int len2, double* outVec, int len) {
    for (int i=0; i< len; i++) {
        outVec[i] = inVec1[i] + inVec2[i];
    }
}

vector<int> getIntVect() {
	vector<int> v {0, 1, 2, 3, 4};
	return v;
}
vector<long> getLongVect() {
	vector<long> v {0, 1, 2, 3, 4};
	return v;
}
vector<float> getFloatVect() {
	vector<float> v {0, 1, 2, 3, 4};
	return v;
}
vector<double> getDoubleVect() {
	vector<double> v {0, 1, 2, 3, 4};
	return v;
}

vector<SimpleStruct*> getObjectVect() {
	vector<SimpleStruct*> v;
	for (int i = 0; i < 5; i++) {
		v[i] = new SimpleStruct{ .x = (double)i, .y = i};
	}
	return v;
}

// -------------------------------------------------------------- Classes

// ------------------------------- Array User (templated class)

template<typename T>
class ArrayUser {
private:
	std::vector<T> _array;
	T _scaleBy;
public:
	ArrayUser(T scaleBy);
	virtual ~ArrayUser();
	void setArray(T* ar, int len);
	void getArray(T* outVec, int len);
};

template <typename T> ArrayUser<T>::ArrayUser(T scaleBy):
	_scaleBy(scaleBy)
{}

template <typename T> ArrayUser<T>::~ArrayUser() {}

template <typename T>
void ArrayUser<T>::setArray(T* ar, int len) {
	// _array.clear();
	// for (int i = 0; i < len; i++) {
	// 	_array.push_back(ar[i] * _scaleBy);		//results in undefined symbol for length error
	// }
	_array.assign(ar, ar+len);	// more efficient, but doesn't scaleBy
	for(unsigned i = 0; i < _array.size(); ++i) {
		_array[i] *= _scaleBy;
	}
}

template <typename T>
void ArrayUser<T>::getArray(T* outVec, int len) {
	size_t numel = len < _array.size() ? len : _array.size();
	memcpy(outVec, &_array[0], sizeof(T)*numel);
}

// ------------------------------- ArrayUser_dbl (wrapper class)

ArrayUser_dbl::ArrayUser_dbl(double scaleBy):
	_pimpl(new ArrayUser<double>(scaleBy))
{}
ArrayUser_dbl::~ArrayUser_dbl() {
	delete _pimpl;
}
void ArrayUser_dbl::setArray(double* ar, int len) {
	_pimpl->setArray(ar,len);
}
void ArrayUser_dbl::getArray(double* outVec, int len) {
	_pimpl->getArray(outVec,len);
}

 #endif // ARRAYFUNCS_CPP

