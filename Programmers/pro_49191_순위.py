from collections import deque
def solution(n, results):
    #자기보다 앞에 있는사람 + 뒤에 있는 사람 = n-1 되도록 bfs2번
    adj1,adj2 =[[] for _ in range(n)],[[] for _ in range(n)]
    for u,v in results:        
        adj1[u-1]+=[v-1]
        adj2[v-1]+=[u-1]

    def getCnt(s, adj):
        que = deque([s])
        visited = [0]*n
        visited[s]=1
        cnt=0
        while que:
            top = que.popleft()
            for i in adj[top]:
                if(visited[i]==0):
                    visited[i]=1
                    que.append(i)
                    cnt+=1
        return cnt
    
    answer=0
    for i in range(n):
        if(getCnt(i,adj1)+getCnt(i,adj2)==n-1):
            answer+=1
    return answer