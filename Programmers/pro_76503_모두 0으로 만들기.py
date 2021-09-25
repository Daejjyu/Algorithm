import sys
sys.setrecursionlimit(300000)

def solution(a, edges):        
    if sum(a) != 0:
        return -1    
    
    N = len(a)
    adj = [[] for _ in range(N)]
    for i, j in edges:
        adj[i].append(j)
        adj[j].append(i)
    
    visited = [0]*N
    answer=[0]
    def dfs(cur):
        now = a[cur]
        visited[cur] = 1
        for i in adj[cur]:
            if visited[i] == 0:
                leafSum = dfs(i)
                answer[0]+=abs(leafSum)
                now += leafSum
        return now
    dfs(0)
    return answer[0]