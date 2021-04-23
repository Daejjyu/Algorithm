import heapq
import sys
input = sys.stdin.readline
N = int(input())
ans=[]
for _ in range(N):
    list1 = list(map(int,input().split()))
    for i in list1:
        if(len(ans)<N):
            heapq.heappush(ans,i)
        else:
            heapq.heappush(ans,i)
            heapq.heappop(ans)
print(ans[0])