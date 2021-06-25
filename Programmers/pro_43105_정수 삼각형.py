def solution(triangle):
    L = len(triangle)
    dp = [[0 for _ in range(x)] for x in range(1,L+1)]
    dp[0][0]=triangle[0][0]
    for r in range(1,L):
        for c in range(r+1):
            if(c==0):
                dp[r][c] = triangle[r][c]+dp[r-1][c]
            elif(c==r):
                dp[r][c] = triangle[r][c]+dp[r-1][c-1]
            else:
                dp[r][c] = triangle[r][c]+max(dp[r-1][c-1],dp[r-1][c])  
    return max(dp[L-1])