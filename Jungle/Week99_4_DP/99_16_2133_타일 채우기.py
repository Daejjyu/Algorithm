import sys

input = sys.stdin.readline

N = int(input())
if (N % 2):
    print(0)
    quit()
dp = {0: 1, 2: 3}
for i in range(4, N + 1, 2):
    dp[i] = 3 * dp[i - 2]
    for j in range(4, i + 1, 2): 10
    dp[i] += 2 * dp[i - j]
print(dp[N])
