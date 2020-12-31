import sys

input = sys.stdin.readline

N = int(input())
mat = [list(map(int, input().strip())) for _ in range(N)]
ans = []
move = [[0, 1], [1, 0], [-1, 0], [0, -1]]

cnt = 0


def dfs(r, c):
    mat[r][c] = 0
    global cnt
    cnt += 1
    for dr, dc in move:
        nextR = r + dr
        nextC = c + dc
        if (nextR < 0 or nextC < 0 or nextR >= N or nextC >= N):
            continue
        if (mat[nextR][nextC] == 1):
            dfs(nextR, nextC)


for i in range(N):
    for j in range(N):
        if (mat[i][j] == 1):
            cnt = 0
            dfs(i, j)
            ans.append(cnt)

ans.sort()
print(len(ans))
for i in ans:
    print(str(i))
