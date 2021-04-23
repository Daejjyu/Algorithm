import sys


# visited를 bitmask로 처리하고 재귀적으로 시작점으로 메모이제이션을 갱신해줌

def solve():
    input = sys.stdin.readline

    N = int(input())

    mat = [list(map(int, input().split())) for _ in range(N)]
    dp = [[-1 for _ in range((1 << N))] for _ in range(N)]

    def TSP(cur, visited):
        if (visited == (1 << N) - 1):
            if (mat[cur][0]):
                return mat[cur][0]
            else:
                return float('inf')
        if (dp[cur][visited] != -1):
            return dp[cur][visited]
        dp[cur][visited] = float('inf')
        for i in range(N):
            if (visited & (1 << i) == 0 and mat[cur][i]):
                dp[cur][visited] = min(dp[cur][visited], mat[cur][i] + TSP(i, visited | (1 << i)))
        return dp[cur][visited]

    print(TSP(0, 1))


solve()
