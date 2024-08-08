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

def min_coins(n, m, a, b):

  if n == m:
    return 0  # Base case: no operations needed

  # Check if halving is feasible (odd target cannot be reached from even number)
  if n % 2 == 0 and m % 2 == 1:
    return b * (n - m)  # Only reduction by one applies

  # Prioritize halving (greedy approach)
  halving_count = 0
  while n > 2 * m:
    n //= 2  # Integer division for halving
    halving_count += 1
  cost_halving = a * halving_count

  # Reduction by one for remaining steps
  remaining_reductions = n - m
  cost_reduction_by_one = b * remaining_reductions

  return min(cost_halving, cost_reduction_by_one)  # Return minimum cost


def solve():
    n, m, a, b = map(int, input().split())
    print(min_coins(n, m, a, b))


if __name__ == '__main__':
    # start = time()
    t = 1
    t = int(input())
    for _ in range(t):
        solve()
    # end = time()
    # print(end - start)
    
