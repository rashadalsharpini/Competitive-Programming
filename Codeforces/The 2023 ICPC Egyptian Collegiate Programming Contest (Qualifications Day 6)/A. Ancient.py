from collections import Counter
from math import gcd, lcm
from bisect import bisect_left, bisect_right
from time import time


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

# def series_sum_specific(k):
#     r = 2
#     term1 = r
#     term2 = (k + 1) * (2 ** -(k + 1))
#     term3 = k * (2 ** -k)
#
#     sum_value = (term1 - term2 + term3) / (r - 1) ** 2
#     return sum_value

MOD = 10**9 + 7


def fast_power(a, b):
    res = 1
    while b:
        if b & 1:
            res *= a % MOD
        a *=a % MOD
        b >>= 1
    return res


def solve():
    r = int(input())
    ans = (fast_power(2, r + 1) - 2 - r) % MOD
    # ans = ((1<<(r+1)) - 2 - r) % MOD
    # ans = (2**(r+1) - 2 - r) % MOD
    if ans < 0:
        ans += MOD
    print(ans)


if __name__ == '__main__':
    # start = time()
    t = 1
    t = int(input())
    for _ in range(t):
        solve()
    # end = time()
    # print(end - start)
    
