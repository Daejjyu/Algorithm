import sys
from collections import deque
r=sys.stdin.readline

N , M = map(int,r().split())

adj = [[] for _ in range(N)]
indegree = [0]*N

que = deque()
for i in range(M):
    u,v = map(int,r().split())
    adj[u-1].append(v-1)
    indegree[v-1]+=1

for i in range(N):
    if(indegree[i]==0):
        que.append(i)

# print(adj)
# print(que)
# print(indegree)
while que:
    top = que.popleft()
    print(top+1 ,end = ' ')

    for i in adj[top]:
        indegree[i] -= 1
        # print(indegree)
        if(indegree[i]==0):
            que.append(i)
