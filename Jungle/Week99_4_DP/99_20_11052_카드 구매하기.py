import sys

input = sys.stdin.readline

N = int(input())
card = list(map(int, input().split()))
dp = [0] * (N + 1)
for i in range(len(card)):
    dp[i + 1] = card[i]

for i in range(1, N + 1):
    for j in range(len(card)):
        if (i + (j + 1) <= N):
            dp[i + (j + 1)] = max(dp[i + (j + 1)], dp[i] + card[j])
# print(dp)
print(dp[N])
