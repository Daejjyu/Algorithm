import sys
from collections import  deque
r = sys.stdin.readline
N = int(r())
M = int(r())

adj_cost = [[] for _ in range(N)]
outdegree = [0]*N
for i in range(M):
    X,Y,K = map(int,r().split())
    adj_cost[Y-1].append([X-1,K])
    outdegree[X-1]+=1
que = deque()
basic = []
for i in range(N):
    if(outdegree[i]==0):
        que.append(i)
        basic.append(i)
topology = []
while que:
    top = que.popleft()
    topology.append(top)
    for i in adj_cost[top]:
        nextN = i[0]
        outdegree[nextN]-=1
        if(outdegree[nextN]==0):
            que.append(nextN)

dp = [[0 for _ in range(N)] for _ in range(N)]
for i in range(len(basic)):
    dp[basic[i]][basic[i]]=1
    adj_cost[basic[i]].append([basic[i],1])

for i in range(len(topology)-1):
    for k in adj_cost[topology[i]]:
        for j in range(len(basic)):
            dp[k[0]][basic[j]] += k[1]*dp[topology[i]][basic[j]]

for i in basic:
    if(i!=N-1):
        print(i+1,dp[N-1][i])