def solution(n):
    board = [[0 for _ in range(n)] for _ in range(n)]
    answer = 0
    def dfs(pos,nCol):
        if nCol == n:
            return 1
        ret = 0
        for r in range(n):
            flag=True
            for prevR,prevC in pos:
                if(r==prevR or abs(nCol-prevC)==abs(r-prevR)):
                    flag=False
                    break
            if(flag):
                pos.append([r,nCol])
                ret += dfs(pos,nCol+1)
                pos.pop()
        return ret
    
    for r in range(n):
        pos = [[r,0]]
        answer += dfs(pos,1)
    return answer