import sys
input = sys.stdin.readline

def solve():
    N,M = map(int,input().split())
    list1 = list(map(int,input().split()))

    cnt, sum, lo,hi = 0,0,0,0
    while(1):
        if(sum>=M):
            sum -= list1[lo]
            lo+=1
        else:
            if(hi==N):
                break
            sum += list1[hi]
            hi+=1
        if(sum==M):
            cnt+=1
    print(cnt)
solve()