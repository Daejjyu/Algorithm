import sys

input = sys.stdin.readline

T = int(input())
dp = {1: 1, 2: 2, 3: 4}
for i in range(4, 11):
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
for _ in range(T):
    print(dp[int(input())])
