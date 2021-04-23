import sys


# 단순히 곱해주는 경우로는 결과가 나오지 않고 모든 순서를 고려해줘야함.
# 재귀적으로 하위레벨의 곱셈을 구해서 상위레벨에 넣어준다.
# 하위 레벨의 곱을 이미 구했는지는 메모이제이션으로 확인
def solve():
    input = sys.stdin.readline

    N = int(input())
    if (N == 1):  # 예외처리
        print(0)
        quit()

    list1 = [list(map(int, input().split())) for _ in range(N)]

    dp = [[-1 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        dp[i][i] = 0

    def min_pow_mat(start, end):  # idx (start - end)
        if (dp[start][end] != -1):
            return dp[start][end]
        dp[start][end] = float('inf')
        for i in range(start, end):
            dp[start][end] = min(dp[start][end],
                                 min_pow_mat(start, i) + min_pow_mat(i + 1, end)
                                 + list1[start][0] * list1[i + 1][0] * list1[end][1])

        return dp[start][end]

    print(min_pow_mat(0, N - 1))

    # for i in range(N):
    #     print(dp[i])


solve()
