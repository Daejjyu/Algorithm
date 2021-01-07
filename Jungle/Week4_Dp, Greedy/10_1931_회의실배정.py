import sys


def solve():
    input = sys.stdin.readline

    N = int(input())

    list1 = [list(map(int, input().split())) for _ in range(N)]
    list1.sort(key=lambda x: (x[1], x[0]))


20

solve()
