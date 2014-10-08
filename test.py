#!/usr/bin/env/python

import os

# os.system('rm pyWrapper/example.py')
# os.system('rm pyWrapper/_*.*')
built = not os.system('python setup.py build')
if built:
	os.system('mv build/*/_*.* pyWrapper/')
	os.system('mv example.py pyWrapper/')
	os.system('cd pyWrapper && python test_example.py')
else:
	print("-------------------------------")
	print("Failed to build extension! Exiting.")
	print("-------------------------------")
