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

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    prefix_gcd = [0] * (n + 1)
    suffix_gcd = [0] * (n + 2)
    for i in range(1, n + 1):
        prefix_gcd[i] = gcd(prefix_gcd[i - 1], a[i - 1])
        
    for i in range(n, 0, -1):
        suffix_gcd[i] = gcd(suffix_gcd[i + 1], a[i - 1])
    for i in range(int(input())):
        x = int(input())
        gcd_excluding = gcd(prefix_gcd[x - 1], suffix_gcd[x + 1])
        print(gcd_excluding)


if __name__ == '__main__':
    # start = time()
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
    # end = time()
    # print(end - start)
    
