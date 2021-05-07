from collections import deque
def solution(people, limit):
    deq = deque(sorted(people))
    answer=0
    #내보낼 수 있다면 (min,max) 쌍으로 무조건 내보내면 된다.
    #불가능 시 max만 내보냄
    while(len(deq)>1):
        if(deq[0]+deq[-1]<=limit):
            deq.popleft()        
        deq.pop()
        answer+=1        
    if(deq):
        answer += 1
    return answer