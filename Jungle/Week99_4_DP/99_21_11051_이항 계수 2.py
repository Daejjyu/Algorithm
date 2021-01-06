import sys

input = sys.stdin.readline

N, K = map(int, input().split())
dp = [[0 for _ in range(N + 1)] for _ in range(N + 1)]
dp[0][0] = 1
for i in range(1, N + 1):
    dp[i][0] = 1
    dp[i][i] = 1
    dp[i][1] = i
    dp[i][i - 1] = i
for n in range(1, N + 1):
    for k in range(1, K + 1):
        dp[n][k] = (dp[n - 1][k - 1] + dp[n - 1][k]) % 10007
print(dp[N][K])
