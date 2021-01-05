import sys


def solve():
    input = sys.stdin.readline
    n, m = map(int, input().split())
    dp = [[float('inf')] * (int((2 * n) ** 0.5) + 2) for _ in range(n)]
    stone = [0] * n

    for _ in range(m):
        stone[int(input()) - 1] = 1

    dp[0][0] = 0

    for i in range(1, n):
        if stone[i]:
            continue
        for j in range(int((2 * i) ** 0.5) + 1):
            dp[i][j] = min(dp[i - j][j - 1], dp[i - j][j], dp[i - j][j + 1]) + 1

    answer = min(dp[n - 1])

    if answer == float('inf'):
        print(-1)
    else:
        print(answer)


solve()
