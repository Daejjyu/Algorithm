import heapq
def toSecond(str):
    _, time, t = str.split(" ")
    h,m,s = time.split(":")
    endTime = int(h)*3600+int(m)*60+float(s)
    startTime = endTime-float(t[:-1])+0.001 #시작시간 포함
    return [startTime,endTime] if startTime>0 else [0,endTime]
    
def solution(lines):
    lines = sorted([toSecond(x) for x in lines])
    answer = 0
    min_end_heap = []
    for s,e in lines: 
        heapq.heappush(min_end_heap,e)
        while(min_end_heap and s-min_end_heap[0]>=1):
            # 어떤 start값에서 끝점을 뺐을 떄 1 이상이면 같은 초 범위에 있지 않다.
            heapq.heappop(min_end_heap)
        answer=max(answer,len(min_end_heap))
    return answer
