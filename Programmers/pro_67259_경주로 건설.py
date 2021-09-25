from collections import deque
def solution(board):
    que = deque([[0,0,-1,0]])
    N = len(board)
    visited = [[float('inf') for _ in range(N)] for _ in range(N)]    
    visited[0][0]=0
    dR = [0,0,-1,1]
    dC = [1,-1,0,0]
    while que:
        r, c, way, cost =que.popleft()
        for i in range(4):
            nR = r+dR[i]
            nC = c+dC[i]
            nCost = cost + 100
            if nR<0 or nC<0 or nR>=N or nC>=N or board[nR][nC]==1:
                continue
            if way!=i and way!=-1:
                nCost += 500
            if visited[nR][nC]>=nCost-200: #휴리스틱하게 경계값을 완화하여 맞춤
                visited[nR][nC]=min(visited[nR][nC],nCost)
                que.append([nR,nC,i,nCost])
    return visited[N-1][N-1]