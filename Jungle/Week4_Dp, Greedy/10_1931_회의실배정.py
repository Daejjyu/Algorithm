import sys


def solve():
    input = sys.stdin.readline

    N = int(input())

    list1 = [list(map(int, input().split())) for _ in range(N)]
    list1.sort(key=lambda x: (x[1], x[0]))
    end, ans = 0, 0
    for s, e in list1:
        if (s >= end):
            ans += 1
            end = e
    print(ans)


solve()
