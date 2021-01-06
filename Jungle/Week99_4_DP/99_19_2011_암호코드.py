import sys

input = sys.stdin.readline

text = input().strip()
N = len(text)
dp = [0] * (N + 1)
if (text[0] == '0'):
    print(0)
    quit()
dp[0] = 1
dp[1] = 1
for i in range(1, len(text)):
    if (text[i] > '0'):
        dp[i + 1] = dp[i]
    if ('10' <= text[i - 1] + text[i] <= '26'):
        dp[i + 1] += dp[i - 1]
    dp[i + 1] %= 1000000
print(dp[N])
