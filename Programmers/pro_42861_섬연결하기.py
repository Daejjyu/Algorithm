def find(parent, N):
    if(parent[N]<0):
        return N
    parent[N] = find(parent, parent[N])
    return parent[N]

def union(parent, a,b,cost):
    a = find(parent, a)
    b = find(parent, b)
    if(a==b):
        return 0
    parent[a] = b            
    return cost

def solution(n, costs):   
    parent=[-1]*n
    costs.sort(key=lambda x: x[2])   
    answer=0
    for i,j,c in costs:
        answer += union(parent, i,j,c)
    return answer