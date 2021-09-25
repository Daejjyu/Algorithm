def solution(tickets):
    tickets.sort()
    l = len(tickets)    
    def dfs(src, path,visited,cnt):
        if(cnt==l): 
            return path
        for i in range(l):
            if visited[i]==0 and tickets[i][0]==src:
                _, dest = tickets[i]
                visited[i]=1
                path.append(dest)
                if(dfs(dest,path,visited,cnt+1)):
                    return path
                visited[i]=0
                path.pop()
    path = dfs('ICN',['ICN'],[0]*l,0)
    return path