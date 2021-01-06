import sys

input = sys.stdin.readline
N = int(input())
list1 = list(map(int, input().split()))
dp = [1] * N
for i in range(N):
    for j in range(i):
        if (list1[i] > list1[j]):
            dp[i] = max(dp[i], dp[j] + 1)
print(max(dp))
