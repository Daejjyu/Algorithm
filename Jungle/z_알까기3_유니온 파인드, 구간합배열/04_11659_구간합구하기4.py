import sys
input = sys.stdin.readline

N,M = map(int,input().split())
list1 = list(map(int,input().split()))

sumrange = [0]*N
sum =0
for i in range(N):
    sum += list1[i]
    sumrange[i] = sum
for _ in range(M):
    s,e = map(int,input().split())
    if(s>1):
        print(sumrange[e-1]-sumrange[s-2])
    else:
        print(sumrange[e-1])
