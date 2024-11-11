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

def solve():
    n, k = map(int, input().split())
    a = [0]*(n+1)
    for i in range(k):
        l, r = map(int, input().split())
        a[l-1] += 1
        a[r] -= 1
    for i in range(1, n+1):
        a[i] += a[i - 1]
    # print(a)
    counts = []
    count = 0
    for i in range(n):
        if a[i]==0:
            count+= 1
        else:
            counts.append(count)
            count = 0
    print(max(counts))


if __name__ == '__main__':
    # start = time()
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
    # end = time()
    # print(end - start)
    
