import random

def f():
    a = []
    for i in range(1,101):
        a.append(random.uniform(0,200))
    a.sort()
    print(a)
f()