def dfs(cur, visited, computers):
    visited[cur]=1
    for i in range(len(computers)):
        if(computers[cur][i]==1 and visited[i]==0):
            dfs(i,visited,computers)    

def solution(n, computers):
    answer = 0
    visited=[0]*n
    for i in range(n):
        if(visited[i]==0):
            answer+=1
            dfs(i, visited,computers)
    return answer