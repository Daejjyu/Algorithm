def rotation(key,state):
    if(state==0):
        return key
    
    M = len(key)
    ret = [[0 for _ in range(M)] for _ in range(M)]
    if(state==1):
        for r in range(M):
            for c in range(M):
                ret[c][M-1-r] = key[r][c]
    elif(state==2):                   
        for r in range(M):
            for c in range(M):
                ret[M-1-r][M-1-c] = key[r][c]
    elif(state==3):
        for r in range(M):
            for c in range(M):
                ret[M-1-c][r] = key[r][c]
    return ret

def checkKey(keyStr,lock,zeroCnt):
    M, N = len(keyStr),len(lock)
    for dr in range(-(M-1),N): #M+N-1개, 20^4
        for dc in range(-(M-1),N):
            cnt=0
            for r in range(M):
                for c in range(M):
                    curR,curC = r+dr,c+dc
                    if(0<=curR<N and 0<=curC<N):
                        if(keyStr[r][c]==1 and lock[curR][curC]==1):#돌기, 돌기
                            cnt=-1
                            break
                        if(keyStr[r][c]==1 and lock[curR][curC]==0):#돌기, 홈
                            cnt+=1
                if(cnt==-1):
                    break
            if zeroCnt==cnt:
                return True
    return False
            
    
def solution(key, lock):
    zeroCnt = len(lock)**2 - sum([sum(x) for x in lock])
    for i in range(4):
        keyArr = rotation(key,i)
        if(checkKey(keyArr,lock,zeroCnt)):
            return True
    return False
