import sys

input = sys.stdin.readline

N = int(input())

list1 = [int(input()) for _ in range(N)]
dp = [0] * N
dp[0] = list1[0]
if (N > 1): dp[1] = list1[0] + list1[1]
if (N > 2): max(list1[0] + list1[1], list1[1] + list1[2], list1[0] + list1[2])
for i in range(3, N):
    dp[i] = dp[i - 1]  # 지금꺼 x
    dp[i] = max(dp[i], dp[i - 2] + list1[i])  # 전꺼
    dp[i] = max(dp[i], dp[i - 3] + list1[i - 1] + list1[i])  # 전전꺼x
print(dp[N - 1])
