# Q4

import random

def genEven():
    return random.randint(0, 49) * 2

#Q5

def deterministicNumber():
    '''
    Deterministically generates and returns an even number between 9 and 21
    '''

    return 10


#Q6

def stdDevOfLengths(L):
    if len(L) <= 0:
        return float("NaN")
    
    s = 0
    n = len(L)
    for i in L:
        s += len(i)
    mu = s / n

    sxx = 0
    for i in L:
        sxx += (len(i) - mu) ** 2
    
    return (sxx / n) ** (1 / 2)

print(stdDevOfLengths(['a', 'z', 'p']))
print(stdDevOfLengths(['apples', 'oranges', 'kiwis', 'pineapples']))