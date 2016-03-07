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

# gather up all the source files
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

# set the compiler flags so it'll build on different platforms (feel free
# to file a  pull request with a fix if it doesn't work on yours)
if sys.platform == 'darwin':
    # default to clang++ as this is most likely to have c++11 support on OSX
    if "CC" not in os.environ or os.environ["CC"] == "":
        os.environ["CC"] = "clang++"
        # we need to set the min os x version for clang to be okay with
        # letting us use c++11; also, we don't use dynamic_cast<>, so
        # we can compile without RTTI to avoid its overhead
        extra_args = ["-stdlib=libc++",
          "-mmacosx-version-min=10.7","-fno-rtti",
          "-std=c++0x"]  # c++11
else: # only tested on travis ci linux servers
    os.environ["CC"] = "g++" # force compiling c as c++
    extra_args = ['-std=c++0x','-fno-rtti']

# inplace extension module
_example = Extension("_example",
                   srcFiles,
                   include_dirs=includeDirs,
                   swig_opts=['-c++'],
                   extra_compile_args=extra_args,
                   )

# NumyTypemapTests setup
setup(  name        = "SWIG Numpy Example",
        description = "Example project to wrap a C/C++ library in Numpy",
        author      = "D Blalock",
        version     = "1.0",
        license     = "MIT",
        ext_modules = [_example]
        )



