import numpy as np

###############################################################################
# 1. np.arange()
###############################################################################
# list
l = [1, 2, 3, 4, 5]
print(l, type(l))

# create ndarray
t1 = np.arange(12)
print(t1, type(t1), t1.shape)

t1 = t1 + 1
print(t1, type(t1), t1.shape)

t1 = t1.reshape(3, 4)
print(t1, type(t1), t1.shape)

###############################################################################
# 2. np.array()
###############################################################################
# list
data = [[1, 2, 3.14, 4], [True, 6, 7, None]]
print(data, type(data))

# create ndarray based on list
t2 = np.array(data)
print(t2, type(t2), t2.shape)

###############################################################################
# 3. np.random()
###############################################################################
t3 = np.random.random(size=[3, 4])
print(t3, type(t3), t3.shape)

t3 = np.random.randint(1, 100, size=(3, 4))
print(t3, type(t3), t3.shape)

t3 = np.random.normal(loc=10, size=[3,4])
print(t3, type(t3), t3.shape)
