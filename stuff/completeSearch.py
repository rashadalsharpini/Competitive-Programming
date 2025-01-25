n = int(input())
for i in range(1 << n):
    sub = []
    for j in range(n):
        if (1<<j) & i:
            sub.append(j)
    print(*sub)

