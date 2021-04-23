import sys

input = sys.stdin.readline

N = int(input())
dp = {1: 1, 2: 3}
for i in range(3, N + 1):
    dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007

print(dp[N])
