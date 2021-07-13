import heapq

def solution(n, works):
    works = [-x for x in works]
    heapq.heapify(works)
    while(n): #logN (N=1000000)
        n-=1
        top = heapq.heappop(works) # O(1)
        if(top==0):
            break
        heapq.heappush(works,top+1) #logM (M=20000)
    return sum([x**2 for x in works])