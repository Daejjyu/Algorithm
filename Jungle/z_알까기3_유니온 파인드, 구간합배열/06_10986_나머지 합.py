import sys

def solve():
    input = sys.stdin.readline
    N,M = map(int,input().split())
    list1 = list(map(int,input().split()))
    remainder = [[] for _ in range(M)]

    psum=0
    for i in range(N):
        psum+=list1[i]
        remainder[psum%M].append(i)

    ans = len(remainder[0])
    for i in range(0,M):
        num = len(remainder[i]) - 1
        if(num>0):
            ans += int((num*(num+1))/2)
    print(ans)
solve()