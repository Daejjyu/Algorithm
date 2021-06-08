def solution(number, k):
    idx=0
    N=len(number)
    answer=''
    while(k and idx+k<N):
        cur = number[idx]
        if(cur!='9'):            
            for i in range(idx+1,idx+1+k):
                if(cur<number[i]):
                    k-=1
                    cur=''
                    break
        answer+=cur
        idx+=1
    answer += number[idx:N-k]
    return answer