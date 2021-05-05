import heapq

def solution(jobs):
    jobs.sort(key = lambda x: x[0])    
    answer = 0
    cur_time=0
    min_heap = []
    
    # 전체 jobs를 끝낼 때 까지
    cur_idx = 0
    while(cur_idx < len(jobs) or len(min_heap)!=0):
        # 진행할 수 있는 것(cur_time >= start_time) 중 
        while(cur_idx < len(jobs)):
            start_time, duration = jobs[cur_idx]
            if(cur_time>= start_time):
                #min_heap 에 (duration, start_time) 순으로 넣기
                heapq.heappush(min_heap,(duration,start_time))        
                cur_idx+=1
            else:
                break

        if(min_heap):            
            #min_heap으로 duration 짧은 것을 먼저 처리, cur_time 늘려주기, 다음loop로
            pop=heapq.heappop(min_heap)
            cur_time+= pop[0] #duration
            answer += cur_time - pop[1] #start_time
        else:
            #heap이 비었다면 
            #cur_time = 다음 idx의 start_time        
            cur_time=start_time
            heapq.heappush(min_heap,(duration,start_time))
            cur_idx+=1

    return int(answer/len(jobs))