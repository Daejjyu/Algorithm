import sys

input = sys.stdin.readline

N, K = map(int, input().split())
dp = [0] * (K + 1)
coin = [int(input()) for _ in range(N)]

dp[0] = 1
for co in coin:
    for k in range(1, K + 1):
        if (k >= co):
            dp[k] += dp[k - co]
    # print(dp)

print(dp[K])
