import sys

sys.setrecursionlimit(50000)


def solve():
    input = sys.stdin.readline
    R, C = map(int, input().split())
    mat = [list(map(int, input().split())) for _ in range(R)]

    dp = [[-1 for _ in range(C)] for _ in range(R)]

    dR = [1, -1, 0, 0]
    dC = [0, 0, 1, -1]

    def dfs(r, c):
        if (dp[r][c] >= 0):
            return dp[r][c]
        if (r == R - 1 and c == C - 1):
            return 1
        dp[r][c] = 0
        for i, j in zip(dR, dC):
            nextR = r + i
            nextC = c + j
            if (nextR < 0 or nextC < 0 or nextR >= R or nextC >= C):
                continue
            if (mat[r][c] > mat[nextR][nextC]):
                dp[r][c] += dfs(nextR, nextC)

        return dp[r][c]

    print(dfs(0, 0))


solve()
