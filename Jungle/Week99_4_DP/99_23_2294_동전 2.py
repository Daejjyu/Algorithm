import sys

input = sys.stdin.readline

N, K = map(int, input().split())
coin = [int(input()) for _ in range(N)]
dp = [float('inf')] * (K + 1)
for i in coin:
    if (i <= K):
        dp[i] = 1

for i in range(1, K + 1):
    for j in coin:
        if (i + j <= K):
            dp[i + j] = min(dp[i + j], dp[i] + 1)
if (dp[K] == float('inf')):
    print(-1)
else:
    print(dp[K])
