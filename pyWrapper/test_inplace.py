#!/usr/bin/env/python

import numpy as np
import inplace

a = np.array((2,3,4),'d')
print(a)
inplace.inplace(a)
print(a)
