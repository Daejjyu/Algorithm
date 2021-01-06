import sys

input = sys.stdin.readline

N = int(input())
list1 = list(map(int, input().split()))
dp = [1] * N

for i in range(N):
    for j in range(i):
        if (list1[i] > list1[j]):
            dp[i] = max(dp[i], dp[j] + 1)

list2 = list1.reverse()
dp2 = [1] * N
for i in range(N):
    for j in range(i):
        if (list1[i] > list1[j]):
            dp2[i] = max(dp2[i], dp2[j] + 1)
ans = 0
for i in range(N):
    ans = max(ans, dp[i] + dp2[N - i - 1] - 1)
print(ans)
