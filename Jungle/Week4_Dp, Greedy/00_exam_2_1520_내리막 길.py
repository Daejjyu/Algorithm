import sys

sys.setrecursionlimit(50000)
input = sys.stdin.readline


def solve():
    R, C = map(int, input().split())
    mat = [list(map(int, input().split())) for _ in range(R)]

    dp = [[-1 for _ in range(C)] for _ in range(R)]
    # dp에는 경우의 수 저장. 가지 못하는 경우의 수가 0 이므로 초기값을 -1로 설정
    dr = [1, -1, 0, 0]
    dc = [0, 0, 1, -1]

    # 하위 경로를 모두 탐색 후 경우의 수를 0,0에 재귀적으로 갱신해줌
    def down(r, c):
        if (r == R - 1 and c == C - 1):
            return 1  # 갈 수 있으면 1 return
        if (dp[r][c] != -1):
            return dp[r][c]  # 이미 계산 했으면 그 값 return
        dp[r][c] = 0  # 가지 못한다면 0 반환
        for i, j in zip(dr, dc):
            nextR = r + i
            nextC = c + j
            if (nextR < 0 or nextC < 0 or nextR >= R or nextC >= C):
                continue
            if (mat[nextR][nextC] < mat[r][c]):
                dp[r][c] += down(nextR, nextC)
        return dp[r][c]

    print(down(0, 0))


solve()
