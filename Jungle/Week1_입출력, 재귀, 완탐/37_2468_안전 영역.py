import sys
sys.setrecursionlimit(50000000)

N = int(input())
height = [0]*N
visited = [[0 for c in range(N)] for r in range(N)]
dR = [0, 0, 1, -1]
dC = [1, -1, 0, 0]

for i in range(N):
    height[i] = list(map(int, input().split()))


def dfs(r, c, rain):
    visited[r][c] = 1

    for i in range(4):
        nextR = r + dR[i]
        nextC = c + dC[i]
        if(nextR >= N or nextC >= N or nextR < 0 or nextC < 0):
            continue
        if(visited[nextR][nextC] == 0 and height[nextR][nextC] > rain):
            dfs(nextR, nextC, rain)

    return


ans = 1
for rain in range(1, 101):
    visited = [[0 for c in range(N)] for r in range(N)]
    cnt = 0
    for i in range(N):
        for j in range(N):
            if(height[i][j] > rain and visited[i][j] == 0):
                dfs(i, j, rain)
                cnt += 1
    ans = max(ans, cnt)

print(ans)
