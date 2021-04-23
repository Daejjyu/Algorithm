#중간값 구하기 알고리즘 https://www.crocus.co.kr/625
import sys
import heapq
N = int(sys.stdin.readline())
max_heap = []
min_heap = []


for i in range(N):
    num = int(sys.stdin.readline())
    if(len(max_heap)<=len(min_heap)):
        heapq.heappush(max_heap,(-num,num))
    else:
        heapq.heappush(min_heap, num)
    if(len(min_heap)>0):
        max_heap_value =max_heap[0][1]
        min_heap_value = min_heap[0]
        if(max_heap_value>min_heap_value):
            #swap
            heapq.heappop(max_heap)
            heapq.heappush(max_heap, (-min_heap_value,min_heap_value))

            heapq.heappop(min_heap)
            heapq.heappush(min_heap, max_heap_value)

    sys.stdout.write('%d\n'%max_heap[0][1])

