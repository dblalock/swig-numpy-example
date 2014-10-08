#! /usr/bin/env python

# System imports
from distutils.core import *
from distutils      import sysconfig
import glob

# Third-party modules - we depend on numpy for everything
import numpy

# Obtain the numpy include directory.  This logic works across numpy versions.
try:
    numpy_include = numpy.get_include()
except AttributeError:
    numpy_include = numpy.get_numpy_include()

srcFiles = ['example.i']
includeDirs = [numpy_include]
srcDir = os.path.abspath('src')
for root, dirnames, filenames in os.walk(srcDir):
  for dirname in dirnames:
    absPath = os.path.join(root, dirname)
    print('adding dir to path: %s' % absPath)
    globStr = "%s/*.c*" % absPath
    files = glob.glob(globStr)
    print(files)
    includeDirs.append(absPath)
    srcFiles += files

print("includeDirs:")
print(includeDirs)
print("srcFiles:")
print(srcFiles)

# import sys
# sys.exit()

# inplace extension module
_example = Extension("_example",
                   # ["example.i","src/impl/basic_funcs.cpp", "src/utils/util.c"],
                   srcFiles,
                   include_dirs = includeDirs,
                   # language='c++',
                   swig_opts=['-c++'],
                   )

# NumyTypemapTests setup
setup(  name        = "inplace function",
        description = "inplace takes a double array and doubles each of its elements in-place.",

        author      = "Egor Zindy",
        version     = "1.0",
        ext_modules = [_example]
        )



