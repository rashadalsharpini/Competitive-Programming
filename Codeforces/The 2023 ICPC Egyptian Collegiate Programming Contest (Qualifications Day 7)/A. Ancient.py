from collections import Counter
from math import gcd, lcm
from bisect import bisect_left, bisect_right
from time import time

MOD = 10 ** 9 + 7

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

def prime_factors(n):
    factors = []

    # Check for the number of 2s that divide n
    while n % 2 == 0:
        factors.append(2)
        n //= 2

    # Check for odd factors from 3 onwards
    for i in range(3, int(n**0.5) + 1, 2):
        while n % i == 0:
            factors.append(i)
            n //= i

    # If n is a prime number greater than 2
    if n > 2:
        factors.append(n)

    return factors

def find_mex(S):
    present = [False] * (len(S) + 1)
    for num in S:
        if num < len(present):
            present[num] = True
    for i in range(len(present)):
        if not present[i]:
            return i
    return len(S)

# better on memory but with time log(b) unlike the shift >> whichs faster but with more memory
def fast_power(a, b):
    res = 1
    while b:
        if b & 1:
            res *= a % MOD
        a *= a % MOD
        b >>= 1
    return res
# xor_val = [0]*int((3*pow(10,5)+1))
# for p in range(1, int((3*pow(10,5)+1))):
#     xor_val[p] = xor_val[p - 1] ^ p
## prefix sum
# for i in range(1, n):
#     a[i] += a[i - 1]
def find_b(a, c):
    possible_b_values = []
    for d in range(1, a + 1):
        if a % d == 0:
            b = (c * d) / a
            if b.is_integer():
                if gcd(a, int(b)) == d:
                    possible_b_values.append(int(b))
    return possible_b_values


def solve():
    a, c = map(int, input().split())
    a = find_b(a, c)
    # print(a)
    if len(a) == 0:
        print(-1)
    else:
        print(min(a))


if __name__ == '__main__':
    # start = time()
    t = 1
    t = int(input())
    for _ in range(t):
        solve()
    # end = time()
    # print(end - start)
    
