import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    mat = [list(map(int, input().split())) for _ in range(2)]
    dp = [[0 for _ in range(2)] for _ in range(N)]
    dp[0][0], dp[0][1] = mat[0][0], mat[1][0]
    if (N > 1):
        dp[1][0], dp[1][1] = mat[1][0] + mat[0][1], mat[0][0] + mat[1][1]
    for i in range(2, N):
        dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + mat[0][i]
        dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + mat[1][i]

    print(max(dp[N - 1]))
