import sys


def solve():
    input = sys.stdin.readline

    str1 = str(input().strip())
    str2 = str(input().strip())
    N = len(str1)
    M = len(str2)
    dp = [[0 for _ in range(M + 1)] for _ in range(N + 1)]

    for i in range(0, N):
        for j in range(0, M):
            if (str1[i] == str2[j]):
                dp[i + 1][j + 1] = dp[i][j] + 1
            else:
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j])


solve()
