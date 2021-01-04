import sys


def solve():
    input = sys.stdin.readline

    str1 = input().strip()
    str2 = input().strip()
    str3 = input().strip()
    N, M, L = len(str1), len(str2), len(str3)

    dp = [[[0 for _ in range(L + 1)] for _ in range(M + 1)] for _ in range(N + 1)]

    for i in range(1, N + 1):
        for j in range(1, M + 1):
            for k in range(1, L + 1):
                dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1],
                                  dp[i - 1][j - 1][k - 1] + (str1[i - 1] == str2[j - 1] and str2[j - 1] == str3[k - 1]))
    print(dp[N][M][L])


solve()
