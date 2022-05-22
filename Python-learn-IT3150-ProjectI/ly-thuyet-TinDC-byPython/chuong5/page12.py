# use list in python replace array
# Python doesn's support built-in array

a = [1, 4, 6, 2]
b = [40.5, 20.1, 100]
c = ['h', 'e', 'l', 'l', 'o']
d = [
    [1, 2, 3],
    [4, 5, 6]
]

# array in Python
import array as ar
a = ar.array('i', [1, 4, 6, 2])
b = ar.array('f', [40.5, 20.1, 100])
c = ar.array('u', ['h', 'e', 'l', 'l', 'o'])
import numpy
d = numpy.array([
    [1, 2, 3],
    [4, 5, 6]
])