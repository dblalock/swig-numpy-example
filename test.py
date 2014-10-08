#!/usr/bin/env/python

import os

os.system('python setup.py build')
os.system('mv build/*/_*.* pyWrapper/')
os.system('mv example.py pyWrapper/')
os.system('cd pyWrapper && python test_example.py')
