from collections import Counter
from math import gcd
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
    print(isprime(29))
    # n, a, b = map(int, input().split())
    # profit = 0
    # while b > a and n != 0:
    #     profit += b
    #     b -= 1
    #     n -= 1
    # profit += (n * a)
    # print(profit)
    # dif = b - a + 1
    # # print("DIF", dif)
    # if dif <= 0:
    #     print(a*n)
    #     return
    # if dif > n:
    #     dif = n
    # z=((dif * (dif + 1)) // 2)
    # print((n - dif) * a + ( b * dif) + dif - z)


if __name__ == '__main__':
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
    
