import sys
import heapq
N = int(sys.stdin.readline())

list1= []
min_heap = []

for i in range(N):
    start, end = map(int,sys.stdin.readline().split())
    if(start>end): start,end = end,start
    list1.append([start,end])

L =int(input())

list1.sort(key = lambda x : x[1])

ans=0
for i in range(N):
    L_start = list1[i][1]-L
    if(list1[i][0]>=L_start):
        heapq.heappush(min_heap,list1[i][0])
    while(min_heap and min_heap[0]<L_start):
            heapq.heappop(min_heap)
    ans = max(ans,len(min_heap))

print(ans)
