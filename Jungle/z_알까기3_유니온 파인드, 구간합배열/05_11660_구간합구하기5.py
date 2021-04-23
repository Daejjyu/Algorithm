import sys
def solve():
    input = sys.stdin.readline

    N,M = map(int,input().split())
    mat = [list(map(int,input().split())) for _ in range(N)]

    sum_range = [[0 for _ in range(N+1)] for _ in range(N+1)]
    for i in range(N):
        for j in range(N):
            sum_range[i+1][j+1] = sum_range[i+1][j] + sum_range[i][j+1] - sum_range[i][j] + mat[i][j]

    for _ in range(M):
        x1,y1,x2,y2= map(int,input().split())
        print(sum_range[x2][y2]-sum_range[x2][y1-1]-sum_range[x1-1][y2]+sum_range[x1-1][y1-1])
solve()