#!/usr/bin/env/python

import numpy as np
import example

example.printStuff()

a = np.array((2,3,4),'d')
print(a)
example.inplace(a)
print(a)
