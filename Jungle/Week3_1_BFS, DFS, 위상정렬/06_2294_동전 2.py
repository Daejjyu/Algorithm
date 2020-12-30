import sys

r = sys.stdin.readline
N, K = map(int, r().split())

num = sorted([int(r()) for n in range(N)])
# # 1. dp
# dp = [10001] * (K + 1)
# dp[0] = 0
# for i in range(N):
#     for j in range(num[i], K + 1):
#         dp[j] = min(dp[j], dp[j - num[i]] + 1)
# # print(dp)
# if (dp[K] == 10001):
#     print(-1)
# else:
#     print(dp[K])

# 2. BFS
from collections import deque

que = deque()

for i in num:
    que.append(i)

ans = 1
visited = [0] * (K + 1)


def bfs():
    global ans
    while (que):
        curSize = len(que)
        while (curSize):
            curSize -= 1
            top = que.popleft()
            # print(top, ans)
            for i in num:
                if (top + i > K):
                    break
                if (top + i == K):
                    return True
                if (visited[top + i] == 0 and top + i < K):
                    que.append(top + i)
                    visited[top + i] = 1
        ans += 1
    return False


if (bfs()):
    print(ans + 1)
else:
    print(-1)
