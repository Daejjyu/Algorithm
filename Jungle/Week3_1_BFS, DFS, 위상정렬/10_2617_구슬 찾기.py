import sys
# sys.setrecursionlimit(300000)
r= sys.stdin.readline
N, M = map(int,r().split())

adj1 = [[] for _ in range(N+1)]
adj2 = [[] for _ in range(N+1)]

for i in range(M):
    u,v = map(int,r().split())
    adj1[u].append(v)
    adj2[v].append(u)

visited1 = [0]*(N+1)
visited2 = [0]*(N+1)

def dfs1(node):
    # print('n',node)
    visited1[node]=1
    cnt=1
    for i in adj1[node]:
        if(visited1[i]==0):
            cnt += dfs1(i)
    return cnt

def dfs2(node):
    visited2[node]=1
    cnt=1
    for i in adj2[node]:
        if(visited2[i]==0):
            cnt += dfs2(i)
    return cnt

half = int(N/2)+1
ans= [0]*(N+1)
for i in range(1,N+1):
    visited1 = [0] * (N + 1)
    visited2 = [0] * (N + 1)
    if(dfs1(i)>half):
        ans[i]= 1
    # print()
    if (dfs2(i) > half):
        ans[i] = 1
# print(ans)
print(sum(ans))
