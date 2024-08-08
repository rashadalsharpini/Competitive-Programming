from collections import Counter
from math import gcd, lcm
from bisect import bisect_left, bisect_right


def isprime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True


def find_mex(S):
    present = [False] * (len(S) + 1)
    for num in S:
        if num < len(present):
            present[num] = True
    for i in range(len(present)):
        if not present[i]:
            return i
    return len(S)

# xor_val = [0]*int((3*pow(10,5)+1))
# for p in range(1, int((3*pow(10,5)+1))):
#     xor_val[p] = xor_val[p - 1] ^ p
## prefix sum
# for i in range(1, n):
#     a[i] += a[i - 1]
def almost_prime(n):
    counter = 0
    for i in range(1, int((n**0.5) + 1)):
        if n % i == 0:
            if isprime(i):
                counter += 1
            if i * i != n and isprime(n // i):
                counter += 1
    return counter == 2

def solve():
    n = int(input())
    counter = 0
    while n > 0:
        if almost_prime(n):
            counter += 1
        n -= 1
    print(counter)



if __name__ == '__main__':
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
    
