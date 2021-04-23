# 45분 소요.. 실수함 ㅜㅜ

import sys
input = sys.stdin.readline

N = int(input())
dp_max = [0]*3
dp_min = [0]*3

for i in range(N):
    mat = list(map(int,input().split()))
    cur_max = dp_max[:]
    cur_min = dp_min[:]
    for j in range(3):
        if (j == 0):  # only right
            dp_max[j] = max(mat[j]+cur_max[j],mat[j]+cur_max[j+1])
            dp_min[j] = min(mat[j]+cur_min[j],mat[j]+cur_min[j+1])
        elif(j==2): # only left
            dp_max[j] = max(mat[j]+cur_max[j],mat[j]+cur_max[j-1])
            dp_min[j] = min(mat[j]+cur_min[j],mat[j]+cur_min[j-1])
        else:
            dp_max[j] = max(mat[j]+cur_max[j],mat[j]+cur_max[j+1],mat[j]+cur_max[j-1])
            dp_min[j] = min(mat[j]+cur_min[j],mat[j]+cur_min[j+1],mat[j]+cur_min[j-1])

print(max(dp_max),min(dp_min))