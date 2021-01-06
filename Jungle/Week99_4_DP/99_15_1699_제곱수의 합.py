import sys


def solve():
    input = sys.stdin.readline

    N = int(input())
    dp = {0: 1}
    for i in range(1, N + 1):
        sqr = int(i ** 0.5)
        if (i == sqr * sqr):
            dp[i] = 1
        else:
            dp[i] = 1e9
            for s in range(1, sqr + 1):
                dp[i] = min(dp[i], dp[i - s * s] + 1)
    print(dp[N])


solve()
