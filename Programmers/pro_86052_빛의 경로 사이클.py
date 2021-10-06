import sys
sys.setrecursionlimit(1000000)
def solution(grid):
    R = len(grid)
    C = len(grid[0])
    grid = [list(x) for x in grid]
    visited = [[[0,0,0,0] for _ in range(C)] for _ in range(R)]
      
    move = [[-1,0],[0,1],[1,0],[0,-1]] #right rotation URDL
    answer = []
    def dfs(r,c,direction,cnt):       
        if visited[r][c][direction]==1:            
            return cnt
        visited[r][c][direction]=1                
        nextR = (r + move[direction][0])%R
        nextC = (c + move[direction][1])%C
        nextD = direction
        nextNode = grid[nextR][nextC]
        if nextNode =='R':
            nextD = (nextD+1)%4
        elif nextNode =='L':
            nextD = (nextD-1)%4
        ret = dfs(nextR,nextC,nextD,cnt+1)       
        return ret
            
    for r in range(R):
        for c in range(C):
            for d in range(4):
                if(visited[r][c][d]==0):
                    answer.append(dfs(r,c,d,0))
    answer.sort()
    return answer