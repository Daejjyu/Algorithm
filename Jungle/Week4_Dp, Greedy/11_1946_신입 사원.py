import sys


def solve():
    input = sys.stdin.readline

    T = int(input())
    for _ in range(T):
        N = int(input())
        list1 = [list(map(int, input().split())) for _ in range(N)]
        list1.sort()

        cnt = 0
        rank_second = list1[0][1]
        for _, j in list1:
            if (rank_second < j):
                cnt += 1
            rank_second = min(rank_second, j)
        print(N - cnt)


solve()
