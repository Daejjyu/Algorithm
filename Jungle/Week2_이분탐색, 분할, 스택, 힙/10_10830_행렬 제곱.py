N,B = map(int,input().split())

#matrix
A = [0]*N

for i in range(N):
    A[i] = list(map(int,input().split()))

def matrix_multipliciation(A,B):
    temp = [[0 for c in range(N)] for r in range(N)]
    size=len(A)
    for r in range(size):
        for c in range(size):
            temp[r][c]=0
            for k in range(size):
                temp[r][c]+=(A[r][k]%1000)*(B[k][c]%1000)
    return temp

def pow_matrix(cnt):
    if(cnt<=1):
        return A
    temp = pow_matrix(int(cnt/2))
    ans = matrix_multipliciation(temp,temp)
    if(cnt%2):
        ans = matrix_multipliciation(A,ans)
    return ans

ans_matrix = pow_matrix(B)

for i in range(N):
    for j in range(N):
        print(ans_matrix[i][j]%1000, end=' ')
    if(i!=N-1):
        print()