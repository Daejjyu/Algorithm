import sys

input = sys.stdin.readline

N = int(input())
dp = [[0 for _ in range(2)] for _ in range(N + 1)]
dp[0][0] = 1
dp[0][1] = 1
dp[1][1] = 1  # 1
dp[1][0] = 0  # x
dp[2][1] = 1  # 11
dp[2][0] = 1  # 00

for i in range(3, N + 1):
    dp[i][0] = (dp[i - 2][1] + dp[i - 2][0]) % 15746
    dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % 15746

print(dp[N][0] + dp[N][1] % 15746)
