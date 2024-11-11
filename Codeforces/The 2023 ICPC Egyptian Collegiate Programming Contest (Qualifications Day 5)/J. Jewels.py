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
def count(s):
    one = 0
    zero = 0
    for i in s:
        if i == 0:
            zero += 1
        else:
            one += 1
    # print(one, zero)
    return one, zero

def check(s):
    ss = []
    for j in range(1, len(s)):
        ss.append(s[j] ^ s[j - 1])
    if 0 not in ss:
        return True
    return False
    


def solve():
    n = int(input())
    s = list(map(int, input()))
    one, zero = count(s)
    if abs(one - zero == 1) or one == zero:
        if check(s):
            print(0)
        else:
            pass
    else:
        print(-1)


if __name__ == '__main__':
    t = 1
    t = int(input())
    for _ in range(t):
        solve()
    
