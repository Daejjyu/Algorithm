import sys


# 놀랍게도 피보나치와 동일
def solve():
    input = sys.stdin.readline

    N = int(input())
    dp = [[0 for _ in range(2)] for _ in range(N + 1)]
    if (N >= 1): dp[1][0], dp[1][1] = 0, 1
    if (N >= 2): dp[2][0], dp[2][1] = 1, 1

    for i in range(3, N + 1):
        dp[i][0] = (dp[i - 2][0] + dp[i - 2][1]) % 15746
        dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % 15746

    print(sum(dp[N]) % 15746)


solve()
