def solution(dirs):
    N = 11
    visited = [[[0 for _ in range(4)] for _ in range(N)] for _ in range(N)] #URDL
    dirChar = ['U','R','D','L']
    dirPos = [[0,1],[1,0],[0,-1],[-1,0]]
    
    curX,curY=5,5
    answer = 0
    for elem in dirs:
        for i in range(4):
            if(elem==dirChar[i]):
                nextX = curX+dirPos[i][0]
                nextY = curY+dirPos[i][1]
                if(0<=nextX<N and 0<=nextY<N):
                    if(visited[nextX][nextY][i]==0):
                        answer+=1
                        visited[nextX][nextY][i]=1
                        visited[curX][curY][(i+2)%4]=1                
                    curX,curY=nextX,nextY
    return answer