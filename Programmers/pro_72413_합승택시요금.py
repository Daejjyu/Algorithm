import heapq
def dijkstra(n,s,adj):
    cost=[float('inf')]*n
    cost[s]=0
    visited=[0]*n
    min_heap =[[0,s]]
    while(min_heap):
        top_cost,top_v = heapq.heappop(min_heap)
        if(visited[top_v]):
            continue
        visited[top_v]=1
        for c,v in adj[top_v]:
            if(visited[v]==0 and cost[v]>top_cost+c):
                cost[v]=top_cost+c
                heapq.heappush(min_heap,[top_cost+c,v])
    return cost
    
def solution(n, s, a, b, fares):
    adj = [[] for _ in range(n)]
    for u,v,c in fares:
        adj[u-1].append([c,v-1])
        adj[v-1].append([c,u-1])       
        
    dijkS=dijkstra(n,s-1,adj)
    dijkA=dijkstra(n,a-1,adj)
    dijkB=dijkstra(n,b-1,adj)
    #다익스트라 3번
    answer=float('inf')
    for i in range(n):
        answer = min(answer,dijkS[i]+dijkA[i]+dijkB[i]) # s->i->a,b  
    return answer