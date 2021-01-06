import sys

input = sys.stdin.readline
K, N = map(int, input().split())

dp = [[0 for _ in range(K + 1)] for _ in range(N + 1)]

for i in range(K + 1):
    dp[1][i] = 1

for n in range(2, N + 1):
    for k in range(K + 1):
        for l in range(k + 1):
            dp[n][k] += dp[n - 1][l]
            dp[n][k] %= 1000000000
# print(dp)
print(dp[N][K])
