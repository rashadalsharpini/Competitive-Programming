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

def solve():
    x = input()
    y = input()
    if x == y:
        print("yes")
        return
    n = len(x)
    m = len(y)
    if n < 8:
        print("no")
        return
    if m - n >= 1:
        print("no")
        return
    if n - m >= 2:
        print("no")
        return
    if n == m:
        count = 0
        for i in range(n):
            if x[i] != y[i]:
                count += 1
        if count >= 2:
            print("no")
            return
    else:
        count = 0
        shit = False
        for i in range(n):
            if x[i] != y[i - shit]:
                count += 1
                shit = True
        if count >= 2:
            print("no")
            return
    print("yes")


if __name__ == '__main__':
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
    
