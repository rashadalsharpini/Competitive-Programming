n, x = map(int, input().split())
num = list(map(int, input().split()))

num.sort(key=lambda num: (abs(num-x), num))
print(*num)
