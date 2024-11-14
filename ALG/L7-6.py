import random

a = tuple([random.randint(0,45) for _ in range(0,6)])
b = tuple([random.randint(0,45) for _ in range(0,45)])
c = a + b
print(c)
print(c.count(0))