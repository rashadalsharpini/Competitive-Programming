def dfs(i, j):
    if i == n or j == m or i < 0 or j < 0:
        return
    if vis[i][j] or mat[i][j] == '#':
        return
    vis[i][j] = True
    dfs(i+1, j)
    dfs(i, j+1)
    dfs(i-1, j)
    dfs(i, j-1)


n, m = map(int, input().split())
mat = [list(input().strip()) for _ in range(n)]
vis = [[False] * m for _ in range(n)]
rooms = 0
for i in range(n):
    for j in range(m):
        if mat[i][j] == '.' and not vis[i][j]:
            dfs(i, j)
            rooms += 1

print(rooms)
