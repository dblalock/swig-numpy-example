#!/usr/bin/env/python

import numpy as np
import example

testNum = 1
def passedTest():
	global testNum
	testNum += 1
	print("Passed Test #%d" % testNum)

def assertEqual(a, b):
	print(a,b)
	assert np.array_equal(a, b)
	passedTest()

def printVar(varName, var):
	print(varName)
	print(var)

# TODO separate test funcs instead of all code at top level

# ================================
# Test 1 - calling cpp successfully
# ================================

example.printStuff()
print("Passed Test #%d" % testNum)

# ================================
# Test 2 - modifying an array in-place
# ================================

a = np.array((2,3,4),'d')
ans = 2 * a.copy()
example.inplace(a)

assertEqual(a, ans)

# ================================
# Test 3 - returning an array
# ================================

ans = np.array((0,3,6,9),'i')	# bonus: this works even with 'd'
output = example.range(4,3)
# output = example.range(3,4)
assertEqual(ans, output)

# ================================
# Test 4 - taking in two arrays and returning an array
# ================================

a = np.array((0,1,2,3),'d')
b = np.array((10,11,12,13),'d')
ans = np.sum(a) + np.sum(b)
output = example.sumOfArrays(a,b)
assertEqual(ans,output)
printVar("output",output)
printVar("ans",ans)
assert output == ans
passedTest()

# ================================
# Test 6 - taking in an array and returning an array
# ================================

a = np.array((0,1,2,5),'d')
ans = 2 * a
output = example.timesTwo(a, a.size) # works, but I have no idea why a can't be only arg
assertEqual(ans,output)

# ================================
# Test 7 - taking in two arrays and returning an array
# ================================

a = np.array((0,1,2,3),'d')
b = np.array((10,11,12,13),'d')
ans = np.array((10,12,14,16),'d')

output = example.addArrays(a, b, a.size) # again, not sure why length is needed...
assertEqual(ans,output)


# ================================
# Test 8 - taking in two arrays and returning an array, with templates
# ================================

# NOTE: This basically just doesn't work. The moral is to not try to wrap
# templated functions directly.

# a = np.array((0,1,2,3),'i')
# b = np.array((10,11,12,13),'i')
# ans = np.array((10,12,14,16),'i')

# output = example.addArrays_int(a,b,a.size) #again, not sure why length is needed...
# assertEqual(ans,output)

assertEqual(1,1) 	# since we aren't actually running the above test

# ================================
# Test 9 - creating a simple class instance and communicating with it
# ================================

ans = 5
instance = example.SimpleClass(5)
assertEqual(ans, instance.get_n())

# ================================
# Test 10 - creating a simple class that uses numpy arrays
# ================================
a = np.array((0,1,2,5),'d')
arInstance = example.SimpleArrayClass()
arInstance.setArray(a)

ans = a.copy()
output = arInstance.getArray(a.size) # note that we have to give it the length
assertEqual(ans, output)

# ================================
# Test 11 - passing an array to a class and retrieving it
# ================================

scale = 10
user = example.ArrayUser_dbl(scale)
a = np.array((0,1,2,3),'d')
ans = scale * a

user.setArray(a)
output = user.getArray(a.size)
assertEqual(ans, output)

# ================================
# Tests 12-15 - receiving vectors as numpy arrays
# ================================

print '------------------------'

out = example.getIntVect()
assertEqual(np.arange(5, dtype=np.int), out)

out = example.getLongVect()
assertEqual(np.arange(5, dtype=np.long), out)

out = example.getFloatVect()
assertEqual(np.arange(5, dtype=np.float), out)

out = example.getDoubleVect()
assertEqual(np.arange(5, dtype=np.double), out)

# TODO get returning vectors of objects to work
# out = example.getObjectVect()
# nObjs = 5
# ans = np.empty(nObjs, dtype=np.object)
# for i in range(nObjs):
# 	ans[i] = example.SimpleStruct(i, i)
# assertEqual(ans, out)

# ================================
# Tests 16-21 - receiving eigen matrices as numpy arrays
# ================================

# ------------------------ doubles
A = np.arange(12).reshape(4, 3)
v = np.arange(4)

M_out = example.createEigenMat()
v_out = example.createEigenVect()
A_out = example.createEigenArray()
u_out = example.createEigenArrayVect()

assertEqual(A, M_out)
assertEqual(v, v_out)
assertEqual(A, A_out)
assertEqual(v, u_out)

# ------------------------ floats
M_out = example.createEigenMatf()
v_out = example.createEigenVectf()
A_out = example.createEigenArrayf()
u_out = example.createEigenArrayVectf()

assertEqual(A, M_out)
assertEqual(v, v_out)
assertEqual(A, A_out)
assertEqual(v, u_out)

# ------------------------ ints
A = A.astype(np.int)
v = v.astype(np.int)

M_out = example.createEigenMati()
v_out = example.createEigenVecti()
A_out = example.createEigenArrayi()
u_out = example.createEigenArrayVecti()

assertEqual(A, M_out)
assertEqual(v, v_out)
assertEqual(A, A_out)
assertEqual(v, u_out)

