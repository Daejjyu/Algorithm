# 1495 기타리스트
# https://www.acmicpc.net/problem/1495
import sys

input = sys.stdin.readline

N, S, M = map(int, input().split())
list1 = list(map(int, input().split()))

dp = [[-2 for _ in range(M + 1)] for _ in range(N)]


def func(idx, volume):
    if (idx == N):  # 도착 시 성공
        return volume
    if (dp[idx][volume] != -2):
        return dp[idx][volume]  # 탐색했던 곳이라면
    dp[idx][volume] = -1  # 탐색 실패 시 -1 반환
    if (volume - list1[idx] >= 0):
        dp[idx][volume] = max(dp[idx][volume], func(idx + 1, volume - list1[idx]))
    if (volume + list1[idx] <= M):
        dp[idx][volume] = max(dp[idx][volume], func(idx + 1, volume + list1[idx]))
    return dp[idx][volume]  # 갱신 실패 시 -1, 성공 시 max값 반환


print(func(0, S))  # 갱신된 dp[0][start]를 출력
