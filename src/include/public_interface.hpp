
#ifndef PUBLIC_INTERFACE_HPP
#define PUBLIC_INTERFACE_HPP

#include <vector>

using std::vector;

// -------------------------------------------------------------- Structs

typedef struct SimpleStruct {
	double x;
	int y;
} SimpleStruct;

// -------------------------------------------------------------- Functions

/** Sanity check function to print out a string using printf */
void printStuff();

/** Modify an array in-place by doubling its elements */
void inplace(double *inVec, int len);

/** Return an array; roughly equivalent to built-in range(n) */
void range(int *outVec, int len, int step);

/** Read in two arrays; return the sum of the elements in both */
double sumOfArrays(double* v1, int len1, double* v2, int len2);

/** Read in an array and return another one (equal to twice the input) */
// void timesTwo(double* v, int inLen, double* outVec, int outLen);
void timesTwo(double* v, int len, double* outVec, int outLen);

/** Add two arrays together and return an array */
void addArrays(double* v1, int len1, double* v2, int len2, double* outVec, int len);

// this doesn't really work;
template <typename T>
void template_add_arrays(T* v1, int len1, T* v2, int len2, T* outVec, int len) {
	for (int i=0; i< len; i++) {
        outVec[i] = v1[i] + v2[i];
    }
}

vector<int> getIntVect();
vector<long> getLongVect();
vector<float> getFloatVect();
vector<double> getDoubleVect();
vector<SimpleStruct*> getObjectVect(); // TODO doesn't work with SWIG

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

// ------------------------------- More complicated class using templates

// forward declare template class; it would be nice to wrap this class
// directly, but this doesn't appear to be possible if we also want to
// use the Numpy typemaps. Basically, you have to tell SWIG which
// type/argname patterns should be mapped to numpy arrays before telling
// it to '%include' a header file, but you have to instantiate the templates
// for a particular class *after* it '%include's the file. As a result, there's
// nothing to map to numpy arrays when it reads in the file. If I'm wrong
// about this, I would love a pull request showing a solution.
template <typename T> class ArrayUser;

// declare type-specific class that uses it (via pimpl idiom)
class ArrayUser_dbl {
private:
	ArrayUser<double> *_pimpl;
public:
	ArrayUser_dbl(double scaleBy);
	~ArrayUser_dbl();
	void setArray(double* ar, int len);
	void getArray(double* outVec, int len);
};


#endif // PUBLIC_INTERFACE_HPP
