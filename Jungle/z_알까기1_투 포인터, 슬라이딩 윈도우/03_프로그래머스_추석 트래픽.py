import heapq
def solution(lines):
    list1 = []
    for line in lines:
        s = line.split()[1:]
        end = s[0].split(':')
        end = int(end[0])*3600+int(end[1])*60+float(end[2])
        start = end - float(s[1][0:-1]) + 0.001
        list1.append([end,start])
    list1.sort(key = lambda x: x[1])
    min_end_heap=[]
    ans = 0
    for i in range(len(list1)):
        cur_start = list1[i][1]
        heapq.heappush(min_end_heap,list1[i][0])
        while min_end_heap and cur_start - min_end_heap[0] >= 1:
            # 어떤 start값에서 끝점을 뺐을 떄 1 이상이면 같은 초 범위에 있지 않다.
            heapq.heappop(min_end_heap)
        ans = max(ans,len(min_end_heap))
    return ans