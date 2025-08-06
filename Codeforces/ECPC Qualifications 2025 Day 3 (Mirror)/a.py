def apply(op, a, b):
    if op == '+':
        return a+b
    if op == '-':
        return a-b
    if op == '*':
        return a*b
    return a//b


def solve():
    a, x, b, y, c = list(input().split())
    a = int(a)
    b = int(b)
    c = int(c)
    high = ['*', '/']
    if x in high and y not in high:
        first = apply(x, a, b)
        res = apply(y, first, c)
    elif y in high and x not in high:
        second = apply(y, b, c)
        res = apply(x, a, second)
    else:
        first = apply(x, a, b)
        res = apply(y, first, c)
    print(res)


if __name__ == '__main__':
    # start = time()
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
    # end = time()
    # print(end - start)
