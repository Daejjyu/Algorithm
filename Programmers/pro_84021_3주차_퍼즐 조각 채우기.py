#https://art-coding3.tistory.com/52
from collections import deque
import copy

dx=[-1,1,0,0]
dy=[0,0,-1,1]

def bfs(x,y,N,visited,array,check):
    space=[]
    que=deque()
    que.append([x,y])
    space.append([x,y])
    visited[x][y] = True
    while que:
        px,py =que.popleft()
        for i in range(4):
            nx=px+dx[i]
            ny=py+dy[i]
            if nx<0 or ny<0 or nx>=N or ny>=N:
                continue
            if visited[nx][ny]==False and array[nx][ny]==check:
                visited[nx][ny]=True
                que.append([nx,ny])
                space.append([nx,ny])
    return sorted(space)

def rotate(b,N):
    new_board=[[block[1],N-1-block[0]] for block in b]
    return new_board

def standard(b,N):
    minx=min([x[0] for x in b])
    miny=min([x[1] for x in b])
    change=[[x[0]-minx,x[1]-miny] for x in b]
    return sorted(change)

def solution(game_board, table):
    answer=0
    N=len(game_board)    
    game_block=[]
    table_block=[]
    visited_g = [[False for _ in range(N)] for _ in range(N)]
    visited_t = [[False for _ in range(N)] for _ in range(N)]
    
    for i in range(N):
        for j in range(N):
            if game_board[i][j]==0 and visited_g[i][j]==False:
                game_block.append(standard(bfs(i,j,N,visited_g,game_board,0),N))
            if table[i][j]==1 and visited_t[i][j]==False:
                table_block.append(standard(bfs(i,j,N,visited_t,table,1),N))
            else:
                continue
    
    for g_block in game_block:
        if g_block in table_block:
            answer+=len(g_block)
            table_block.remove(g_block)
        else:
            flag=False
            for t_block in table_block:
                temp=copy.copy(t_block)
                for z in range(4):
                    if g_block==temp:
                        answer+=len(g_block)
                        table_block.remove(t_block)
                        flag=True
                        break
                    temp=standard(rotate(temp,N),N)
                if flag:
                    break    
    return answer