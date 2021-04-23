import sys


# jump 등차수열로 증가하기 때문에 최대 공간 복잡도를 정해줄 수 있다는 점이 포인트... ㄷㄷ

def solve():
    sys.setrecursionlimit(50000)
    input = sys.stdin.readline

    N, M = map(int, input().split())
    stone = [0] * (N + 1)
    for i in range(M):
        stone[int(input()) - 1] = 1
    max_speed = 2 * (N ** 0.5)
    dp = [[-1 for _ in range(int(max_speed) + 1)] for _ in range(N)]

    def jump(idx, speed):
        if (idx == N - 1):
            return 0  # 도착하면 횟수 그대로
        if (dp[idx][speed] != -1):
            return dp[idx][speed]
        dp[idx][speed] = float('inf')
        for i in range(-1, 2):
            if (0 < i + speed <= max_speed and idx + i + speed < N and stone[idx + i + speed] == 0):
                dp[idx][speed] = min(dp[idx][speed], jump(idx + i + speed, i + speed) + 1)
        return dp[idx][speed]

    ans = jump(0, 0)
    if (ans == float('inf')):
        print(-1)
    else:
        print(ans)


solve()
# 다른 풀이
# import sys
#
#
# def solve():
#     input = sys.stdin.readline
#     n, m = map(int, input().split())
#     dp = [[float('inf')] * (int((2 * n) ** 0.5) + 2) for _ in range(n)]
#     stone = [0] * n
#
#     for _ in range(m):
#         stone[int(input()) - 1] = 1
#
#     dp[0][0] = 0
#
#     for i in range(1, n):
#         if stone[i]:
#             continue
#         for j in range(int((2 * i) ** 0.5) + 1):
#             dp[i][j] = min(dp[i - j][j - 1], dp[i - j][j], dp[i - j][j + 1]) + 1
#
#     answer = min(dp[n - 1])
#
#     if answer == float('inf'):
#         print(-1)
#     else:
#         print(answer)
#
#
# solve()
