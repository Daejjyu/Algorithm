N = int(input())

way = [0]*N
visited = [0]*N

for i in range(N):
    way[i] = list(map(int, input().split()))


ans = 1e9


def dfs(origin, pos, cnt, cost):
    # print(origin, pos, cnt, cost)
    if(cnt == N-1):
        if(way[pos][origin] == 0):
            return
        else:
            cost += way[pos][origin]
            global ans
            ans = min(ans, cost)
            return

    for i in range(N):
        if(visited[i] == 0 and way[pos][i] > 0):
            visited[i] = 1
            dfs(origin, i, cnt+1, cost+way[pos][i])
            visited[i] = 0


for i in range(N):
    for j in range(N):
        if(way[i][j] > 0):
            visited[i] = 1
            visited[j] = 1
            dfs(i, j, 1, way[i][j])
            visited[i] = 0
            visited[j] = 0


print(ans)
