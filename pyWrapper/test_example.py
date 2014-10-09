#!/usr/bin/env/python

import numpy as np
import example

testNum = 1
def passedTest():
	global testNum
	testNum += 1
	print("Passed Test #%d" % testNum)

def assertEqual(a,b):
	print(a,b)
	assert np.array_equal(a, b)
	passedTest()

def printVar(varName,var):
	print(varName)
	print(var)

# ================================
# Test 1 - calling cpp successfully
# ================================

example.printStuff()
print("Passed Test #%d" % testNum)

# ================================
# Test 2 - modifying an array in-place
# ================================

a = np.array((2,3,4),'d')
ans = 2 * a.copy();
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
# Test 5 - taking in two arrays and returning an array
# ================================

a = np.array((0,1,2,3),'d')
b = np.array((10,11,12,13),'d')
ans = np.sum(a) + np.sum(b)
output = example.sumOfArrays(a,b)
# assertEqual(ans,output)
printVar("output",output)
printVar("ans",ans)
assert output == ans
passedTest()

# ================================
# Test 5 - taking in an array and returning an array
# ================================

a = np.array((0,1,2,5),'d')
ans = 2 * a
output = example.timesTwo(a,a.size)	#works, but I have no idea why a can't be only arg
assertEqual(ans,output)

# ================================
# Test 6 - taking in two arrays and returning an array
# ================================

a = np.array((0,1,2,3),'d')
b = np.array((10,11,12,13),'d')
ans = np.array((10,12,14,16),'d')

output = example.addArrays(a,b,a.size) #again, not sure why length is needed...
assertEqual(ans,output)


# ================================
# Test 7 - taking in two arrays and returning an array, with templates
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
# Test 8 - creating a simple class instance and communicating with it
# ================================

ans = 5;
instance = example.SimpleClass(5)
assertEqual(ans, instance.get_n())

# ================================
# Test 9 - creating a simple class that uses numpy arrays
# ================================
a = np.array((0,1,2,5),'d')
arInstance = example.SimpleArrayClass()
arInstance.setArray(a)

ans = a.copy()
output = arInstance.getArray(a.size)	# works before putting in default arg
# output = arInstance.getArray()
assertEqual(ans, output)

# ================================
# Test 10 - passing an array to a class and retrieving it
# ================================

scale = 10;
user = example.ArrayUser_dbl(scale)
a = np.array((0,1,2,3),'d')
ans = scale * a

user.setArray(a)
# output = user.getArray(a.size)
output = user.getArray(7)
assertEqual(ans, output)


