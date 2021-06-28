from collections import Counter
def solution(a):
    L = len(a)
    if(L==1):
        return 0
    numCnt=Counter(a)
    answer=0
    for k, v in numCnt.items():
        if numCnt[k]*2<answer:
            continue
        idx = 0        
        length =0
        while idx < L-1:
            if(a[idx]!=k and a[idx+1]!=k) or a[idx] == a[idx+1]:
                idx+=1
                continue
            length+=2
            idx+=2        
        answer = max(answer,length)
    return answer