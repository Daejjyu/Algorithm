import sys


def solve():
    input = sys.stdin.readline

    N, K = map(int, input().split())
    coin = [int(input()) for _ in range(N)]

    ans = 0
    for i in range(len(coin) - 1, -1, -1):
        ans += (int(K / coin[i]))
        K = int(K % coin[i])
        if (K == 0):
            break
    print(ans)


solve()
