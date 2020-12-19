import heapq
N = int(input())
height = list(map(int,input().split()))

que = []
ans = [0]*N

for i in range(N-1,-1,-1): #역순 index
    N = 0
    while(1):
        if(que and height[i]>que[0][0]):
            ans[que[0][1]] = i + 1
            N += 1
            heapq.heappop(que) # O(log n)
        else:
            break
    heapq.heappush(que,(height[i],i)) # O(log n)

for i in ans:
    print(i, end=' ')
