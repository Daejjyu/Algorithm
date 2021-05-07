from collections import deque
def solution(n, edge):
    adj=[[] for _ in range(n)]
    for v1, v2 in edge:
        adj[v1-1].append(v2-1)
        adj[v2-1].append(v1-1)
    que = deque([0])
    visited = [-1]*n
    visited[0]=0   
    cnt=0
    while que:
        cnt+=1
        for _ in range(len(que)):
            cur = que.popleft()
            visited[cur]=cnt
            for i in adj[cur]:
                if(visited[i]==-1):
                    visited[i]=1
                    que.append(i)           
    answer = 0
    m = max(visited)
    for i in visited:
        if(i==m):
            answer+=1
    return answer