import sys
input =sys.stdin.readline

N = int(input())
M = int(input())
parent = [-1]*N

def union(a,b):
    a = find(a)
    b = find(b)
    if(a==b):
        return
    parent[b]=a

def find(n):
    if(parent[n]<0):
        return n
    parent[n]=find(parent[n])
    return parent[n]

for i in range(N):
    connect = list(map(int,input().split()))
    for j in range(N):
        if(connect[j] and j!=i):
            union(i,j)

travel =list(map(int,input().split()))


# 예외처리 N보다 큰 도시가 들어올 수 있다.
travel.sort()
if(travel[-1]>N):
    print("NO")
    quit()
flag = find(travel[0]-1)

for i in range(1,M):
    if(flag!=find(travel[i]-1)):
        print("NO")
        quit()
print("YES")