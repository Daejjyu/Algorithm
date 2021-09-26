from collections import deque
def solution(places):
    answer = []
    N=5        
    DR = [1,-1,0,0]
    DC = [0,0,1,-1]
    for place in places:        
        que = deque()
        for r in range(N):
            for c in range(N):
                if(place[r][c]=='P'):
                    que+=[[r,c]]
        ret = 1
        while que:
            topR, topC = que.popleft()
            def checkDist(r,c,dist):
                flag = True
                for dr,dc in zip(DR,DC):
                    nR = r + dr
                    nC = c + dc
                    if nR<0 or nC<0 or nR>=N or nC>=N:
                        continue
                    if place[nR][nC]=='P' and not (nR==topR and nC==topC):
                        return False
                    if place[nR][nC]=='O' and dist==1:
                        flag = flag and checkDist(nR,nC,2)
                return flag
            if(checkDist(topR,topC,1)==False):
                ret=0
                break      
        answer.append(ret)
    return answer