def fact(n):
    if n<=1:
        return 1
    return n*fact(n-1)


def nCr(n, r):
    return fact(n)/(fact(r)*fact(n-r))


n, r = map(int ,input().split())
print(int(nCr(n, r)))
