from collections import defaultdict,deque
# https://walwal234.tistory.com/37
def solution(board, r, c):
    d = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    visited = defaultdict(int)
    answer = 0
    b="".join(["".join(map(str,x)) for x in board])    
    q=deque([[r,c,b,0,-1]])

    while q:
        y, x, b, c, e = q.popleft()
        pos = 4 * y + x

        if(visited[str(c)+str(e)+b+str(y)+str(x)]>0):
            continue
        visited[str(c)+str(e)+b+str(y)+str(x)]=1
        
        if(b.count("0")==16):
            return c
        
        for dy,dx in d:
            isLast=0
            tempY,tempX=0,0
            for k in range(1,4):
                ny,nx=y+dy*k,x+dx*k
                nPos = 4*ny+nx
                if(0<=ny<4 and 0<=nx<4):
                    if(k==1):
                        q.append((ny,nx,b,c+1,e))
                    else:
                        if(b[nPos]=="0"):
                            isLast=1
                            tempY,tempX=ny,nx
                        else:
                            q.append((ny,nx,b,c+1,e))
                    if(b[nPos]!="0"):
                        isLast=0
                        break
            if(isLast):
                q.append((tempY,tempX,b,c+1,e))

        if(b[4*y+x]!="0"):
            pos=4*y+x
            if e == -1:
                n_e = pos
                q.append((y, x, b, c+1, n_e))
            elif(e != pos and b[e]==b[pos]):
                    b= b.replace(b[e],"0")
                    q.append((y, x, b, c+1, -1))

    return answer