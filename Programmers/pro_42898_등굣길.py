def solution(m, n, puddles):
    MOD = 1000000007
    nCol = m
    nRow = n
    dp = [[0 for _ in range(nCol+1)] for _ in range(nRow+1)]
    dp[1][1]=1
    for c,r in puddles:
        dp[r][c]=-1
    for r in range(1,nRow+1):
        for c in range(1,nCol+1):        
            if(r==1 and c==1):
                continue
            if(dp[r][c]==-1):
                dp[r][c]=0
            else:
                dp[r][c]=(dp[r-1][c]+dp[r][c-1])%MOD
    return dp[nRow][nCol]
