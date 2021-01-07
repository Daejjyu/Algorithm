import sys


def solve():
    input = sys.stdin.readline

    N = int(input())
    floor = [int(input()) for _ in range(N)]
    dp = [0 for _ in range(N)]
    dp[0] = floor[0]
    if (N >= 2):
        dp[1] = floor[0] + floor[1]
    if (N >= 3):
        dp[2] = max(floor[0] + floor[2], floor[1] + floor[2])
    for i in range(3, N):  # 현재 계단은 밟아야 목적지에 도착
        dp[i] = max(dp[i], dp[i - 3] + floor[i - 1] + floor[i])  # 이전꺼 밟기
        dp[i] = max(dp[i], dp[i - 2] + floor[i])  # 전전꺼 밟기
    print(dp[N - 1])


solve()
