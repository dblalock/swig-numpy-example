Python/Numpy Wrapper Example
==================================================

A simple project showing how to wrap a C/C++ library in Numpy using [SWIG](http://www.swig.org).

The examples in [the documentation](http://www.swig.org/Doc1.3/Python.html) are good, but simple, and don't make clear the subtleties associated with wrapping realistic functions using Numpy arrays (e.g., what if we want to take in two arrays as arguments?). This project contains a collection of example functions for several common function signatures, both inside and outside of classes. It also contains notes on steps I found necessary in getting all of this working.

Other resources for SWIG + Python include the [Scipy SWIG documentation](http://wiki.scipy.org/Cookbook/SWIG_NumPy_examples), the [Numpy SWIG tests](https://github.com/numpy/numpy/tree/master/tools/swig), and this [example of wrapping C++ in Numpy](https://github.com/splewis/statistics-swig-example).
