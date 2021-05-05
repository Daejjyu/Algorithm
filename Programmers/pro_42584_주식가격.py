import heapq

def solution(prices):
    max_heap = [(-prices[0],0)]
    answer = [-1]*len(prices)
    for i in range(1, len(prices)):                
        while(max_heap and -max_heap[0][0] > prices[i]):
            answer[max_heap[0][1]]= i - max_heap[0][1]
            heapq.heappop(max_heap)
        heapq.heappush(max_heap,(-prices[i],i))
    for i in range(len(answer)):
        if(answer[i]==-1):
            answer[i]= len(prices)-i-1
    return answer