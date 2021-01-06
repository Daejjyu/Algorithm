import sys


def solve():
    input = sys.stdin.readline
    # i번째 아이템을 넣을지 말지 결정해야 한다는 것이 포인트 1
    # dp 에는 가치를 저장함 2
    # 0,0번쨰에 재귀적으로 체크하며 가치의 최대값을 갱신해나간다는 것이 포인트 3
    N, K = map(int, input().split())

    items = [list(map(int, input().split())) for _ in range(N)]
    dp = [[-1 for _ in range(K + 1)] for _ in range(N)]

    # 가치가 0 일수도 있으므로 -1로 초기화

    def knapsack(item_num, total_w):
        if (item_num == N):
            return 0  # 인덱스 넘었으므로 value 0
        if (dp[item_num][total_w] != -1):
            return dp[item_num][total_w]
        dp[item_num][total_w] = 0
        W, V = items[item_num]
        # 안넣는 경우
        dp[item_num][total_w] = max(dp[item_num][total_w], knapsack(item_num + 1, total_w))
        if (total_w + W <= K):  # 무게 한도 괜찮다면
            dp[item_num][total_w] = max(dp[item_num][total_w], V + knapsack(item_num + 1, total_w + W))
        # 넣는 경우
        return dp[item_num][total_w]

    print(knapsack(0, 0))


solve()
