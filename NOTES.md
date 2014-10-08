
We need to have the _whatever.so in the same dir as the whatever.py file that gets generated

If its cpp files, you need to pass swig_opts=['-c++'] as a kwarg to the Extension constructor
	Otherwise you get:

	ImportError: dlopen(/Users/davis/Desktop/swig_scratch/pyWrapper/_inplace.so, 2): Symbol not found: _inplace
  Referenced from: /Users/davis/Desktop/swig_scratch/pyWrapper/_inplace.so
  Expected in: dynamic lookup

  You can tell if this is missing because the swig command will be:

  	swig -python -o inplace_wrap.c inplace.i

  instead of:

  	swig -python -c++ -o inplace_wrap.cpp inplace.i

 Note also that language='c++' wasn't necessary as a kwarg to the extension

