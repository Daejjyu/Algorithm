import sys


# 2차원 배열, 문자가 같을 경우 x,y방향 모두 +1
# 조건 만족 시 다음 탐색이 대각선 방향으로 증가한다는 것이 포인트
def solve():
    input = sys.stdin.readline

    str1 = input().strip()
    str2 = input().strip()
    N = len(str1)
    M = len(str2)
    dp = [[0 for _ in range(M + 1)] for _ in range(N + 1)]  # 첫 row, col은 모두 0으로 채움.

    for i in range(N):
        for j in range(M):
            if (str1[i] == str2[j]):  # 문자가 같으면
                dp[i + 1][j + 1] = dp[i][j] + 1
            else:  # 다르면
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j])

    # for i in range(M + 1):
    #     print(dp[i])

    print(dp[N][M])


solve()
