import sys


def solve():
    input = sys.stdin.readline

    S = input().strip()
    N = len(S)
    M = int(input())
    list1 = [input().strip() for _ in range(M)]
    visited = [[0 for _ in range(M)] for _ in range(N)]

    def check(cur):
        if (cur == N):
            print(1)
            quit()
        for i in range(M):
            if (visited[cur][i] == 1):
                continue
            else:
                visited[cur][i] = 1
                if (cur + len(list1[i]) <= N and S[cur:cur + len(list1[i])] == list1[i]):
                    check(cur + len(list1[i]))

    check(0)
    print(0)


solve()
