from collections import deque
def solution(maps):
    R = len(maps)
    C = len(maps[0])
    visited=[[0 for _ in range(C)] for _ in range(R)]
    
    move1 = [1,0,0,-1]
    move2 = [0,1,-1,0]
    
    que = deque([(0,0)])
    visited[0][0]=1
    answer = 0
    while(que):
        answer+=1
        for i in range(len(que)):
            topR, topC = que.popleft()
            for dr, dc in zip(move1,move2):
                nextR = topR + dr
                nextC = topC + dc
                if(0<=nextR<R and 0<=nextC<C and maps[nextR][nextC]==1 and visited[nextR][nextC]==0):
                    if(nextR==R-1 and nextC==C-1):
                        return answer + 1
                    visited[nextR][nextC]=1
                    que.append((nextR,nextC))
    return -1