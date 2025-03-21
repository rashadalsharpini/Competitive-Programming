def solve():
    t = input().strip()
    n = len(t)
    count_a = t.count('a')
    if (n + count_a) % 2 != 0:
        print(":(")
        return
    s_length = (n + count_a) // 2
    s = t[:s_length]
    s_prime = s.replace('a', '')
    if s + s_prime == t:
        print(s)
    else:
        print(":(")


if __name__ == '__main__':
    solve()
