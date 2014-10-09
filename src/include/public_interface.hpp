
#ifndef PUBLIC_INTERFACE_HPP
#define PUBLIC_INTERFACE_HPP

#include <vector>

// -------------------------------------------------------------- Functions

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

// template <typename T>
// void template_add_arrays(T* v1, int len1, T* v2, int len2, T* outVec, int len);
template <typename T>
void template_add_arrays(T* v1, int len1, T* v2, int len2, T* outVec, int len) {
	for (int i=0; i< len; i++) {
        outVec[i] = v1[i] + v2[i];
    }
}

// -------------------------------------------------------------- Classes

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

class SimpleArrayClass {
private:
	std::vector<double> _array;
public:
	void setArray(double *v, int len) {
		_array.assign(v, v+len);
	}
	void getArray(double *outVec, int len) {
		for(unsigned i = 0; i < _array.size(); ++i) {
			outVec[i] = _array[i];
		}
	}
};


// ------------------------------- More complicated stuff that doesn't quite work...


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
	memcpy(outVec, &_array[0], sizeof(T)*len);
}

// forward declare template class
// template <typename T> class ArrayUser;

// declare type-specific class that uses it (via pimpl idiom)
class ArrayUser_dbl {
private:
	ArrayUser<double> *_pimpl;
public:
	ArrayUser_dbl(double scaleBy):
		_pimpl(new ArrayUser<double>(scaleBy)) 
	{}
	~ArrayUser_dbl() {
		delete _pimpl;
	}
	void setArray(double* ar, int len) {
		_pimpl->setArray(ar,len);
	}
	void getArray(double* outVec, int len) {
		_pimpl->getArray(outVec,len);
	}
};


#endif // PUBLIC_INTERFACE_HPP
