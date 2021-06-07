import heapq

def solution(N, road, K):
    adj = [[] for _ in range(N)]
    
    for u,v,d in road:
        adj[u-1]+=[[v-1,d]] #node , dist
        adj[v-1]+=[[u-1,d]]
    
    cost = [0] + [float('inf')]*(N-1)
    visited=[0] *N
    min_heap = [[0,0]] #dist, node
    while min_heap:
        top_cost,top_idx = heapq.heappop(min_heap)
        if(top_cost>K):
            break
        if(visited[top_idx]==1):
            continue
        visited[top_idx]=1
        for i, d in adj[top_idx]:
            if(visited[i]==0 and cost[i] > top_cost+d):
                cost[i]=top_cost+d
                heapq.heappush(min_heap,[cost[i],i])    

    return sum(visited)