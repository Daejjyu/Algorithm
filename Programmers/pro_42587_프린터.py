import heapq
from collections import deque

def solution(priorities, location):
    max_heap = []
    idx_prio = deque()
    for idx, num in enumerate(priorities):
        heapq.heappush(max_heap,-num)
        idx_prio.append((num,idx))
    
    cnt=0
    while(True):
        top = idx_prio.popleft()
        if(top[0]== -1*max_heap[0]):
            cnt+=1
            if(top[1]==location):
                break
            heapq.heappop(max_heap)
        else:
            idx_prio.append(top)         
    return cnt