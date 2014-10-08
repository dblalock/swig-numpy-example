
#ifndef PUBLIC_INTERFACE_HPP
#define PUBLIC_INTERFACE_HPP

#include <vector>

/** Sanity check function to print out a string using printf */
void printStuff();

/** Simple function to modify an array in-place by doubling its elements */
void inplace(double *invec, int n);

/** A function that operates on a read-only array
 * @return The sum of the elements in the array */
int array_read_func(const double* ar, int len);

/** A function that modifies an array in-place. Specifically, sets
 * each element to the cumulative sum of all elements so far, starting
 * at index 0. */
void array_modify_func(double* ar, int len);

/** A templated function that operates on a read-only array
 * @return The sum of the elements in the array */
template <typename T>
T template_array_read_func(const T* ar, int len);



// the below stuff makes it freak out and not find ArrayUser::setArray

class ArrayUser {
private:
	std::vector<double> _array;
public:
	// ArrayUser();
	// ~ArrayUser();
	void setArray(const double* ar, int len);
};

template<typename T>
class TemplatedArrayUser {
private:
	std::vector<T> _array;
public:
	// TemplatedArrayUser();
	// ~TemplatedArrayUser();
	void setArray(const T* ar, int len);
};

#endif // PUBLIC_INTERFACE_HPP
