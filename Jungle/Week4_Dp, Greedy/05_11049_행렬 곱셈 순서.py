import sys


def solve():
    input = sys.stdin.readline

    N = int(input())
    if (N == 1):
        print(0)
        quit()

    list1 = [list(map(int, input().split())) for _ in range(N)]
    dp = [[-1 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        dp[i][i] = 0

    def matmat(s, e):
        if (dp[s][e] >= 0):
            return dp[s][e]
        dp[s][e] = 1e9
        for i in range(s, e):
            dp[s][e] = min(dp[s][e], matmat(s, i) + matmat(i + 1, e) + list1[s][0] * list1[i + 1][0] * list1[e][1])
        return dp[s][e]

    print(matmat(0, N - 1))


solve()
