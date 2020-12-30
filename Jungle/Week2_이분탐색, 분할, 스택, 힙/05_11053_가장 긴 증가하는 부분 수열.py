N = int(input())
A = list(map(int, input().split()))

dp = [1]*(N+1)

for i in range(N):
    for j in range(i):
        if(A[i] > A[j]):
            dp[i] = max(dp[i], dp[j]+1)
print(max(dp))
