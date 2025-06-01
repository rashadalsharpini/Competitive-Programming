Max = 7_000_000
is_prime = [True] * Max
primes = []  # empty list for primes
prefPrimes = []  # will be sized after sieve


def sieve():
    global primes
    is_prime[0] = False
    is_prime[1] = False
    for i in range(4, Max, 2):
        is_prime[i] = False
    for i in range(3, int(Max**0.5) + 1, 2):
        if is_prime[i]:
            for j in range(i * i, Max, i * 2):
                is_prime[j] = False
    primes = [i for i, val in enumerate(is_prime) if val]


def solve():
    n = int(input())
    v = list(map(int, input().split()))
    v.sort(reverse=True)
    pref = [0] * (n + 1)
    for i in range(1, n + 1):
        pref[i] = pref[i - 1] + v[i - 1]
    ans = 0
    for i in range(1, n + 1):
        if i < len(prefPrimes) and pref[i] >= prefPrimes[i]:
            ans = i
        else:
            break
    print(n - ans)


def main():
    global prefPrimes
    sieve()
    prefPrimes = [0] * (len(primes) + 1)
    for i in range(1, len(primes) + 1):
        prefPrimes[i] = prefPrimes[i - 1] + primes[i - 1]

    for _ in range(int(input())):
        solve()


if __name__ == '__main__':
    main()
