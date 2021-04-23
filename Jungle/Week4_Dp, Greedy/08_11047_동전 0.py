import sys

sys.setrecursionlimit(50000)


def solve():
    N, K = map(int, input().split())
    coin = [int(input()) for _ in range(N)]
    coin.reverse()

    ans = 0
    for i in coin:
        if (K / i):
            ans += int(K / i)
        K %= i
    print(ans)


solve()
