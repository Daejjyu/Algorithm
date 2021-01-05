import sys


def solve():
    input = sys.stdin.readline

    N = int(input())
    mat = [list(map(int, input().split())) for _ in range(N)]
    dp = {}

    def TSP(cur, visited):
        if (visited == (1 << N) - 1):
            if (mat[cur][0]):
                return mat[cur][0]
            else:
                return float('inf')
        ret = dp.get((cur, visited))
        if (ret is not None):
            return ret
        dp[(cur, visited)] = float('inf')
        for i in range(N):
            if (visited & (1 << i)): continue
            if (mat[cur][i] == 0): continue
            dp[(cur, visited)] = min(dp[(cur, visited)], TSP(i, visited | (1 << i)) + mat[cur][i])
        return dp[(cur, visited)]

    print(TSP(0, 1))


solve()
