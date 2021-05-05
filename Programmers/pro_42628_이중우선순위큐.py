import heapq

def solution(operations):
    min_heap=[]
    max_heap=[]
    size=0
    for cmd in operations:
        if(cmd[0]=="I"):
            heapq.heappush(min_heap,int(cmd[2:]))
            heapq.heappush(max_heap,-int(cmd[2:]))
            size+=1
        elif(size>0):    
            if(cmd[2]=="1"):
                heapq.heappop(max_heap)
            else:
                heapq.heappop(min_heap)
            size-=1
            if(size==0):
                min_heap=[]
                max_heap=[]
    if(size==0):
        return [0,0]
    if(size==1):
        if(min_heap[0]>0):
            return [min_heap[0],0]
        else:
            return [0,min_heap[0]]
    return [-max_heap[0],min_heap[0]]
