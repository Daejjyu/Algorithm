import sys
from collections import deque

input = sys.stdin.readline

N, K = map(int, input().split())
if (N == K):
    print(0)
    quit()

que = deque()
que.append(N)
visited = [0] * (100001)
visited[N] = 1

time = 0

while que:
    for _ in range(len(que)):
        pos = que.popleft()
        next = []
        next.append(pos - 1)
        next.append(pos + 1)
        next.append(2 * pos)
        for i in next:
            if (i == K):
                print(time + 1)
                quit()
            if (0 <= i <= 100000 and visited[i] == 0):
                visited[i] = 1
                que.append(i)
    time += 1
