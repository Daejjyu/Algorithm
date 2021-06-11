def solution(n):
    answer,acc=0,0
    s,e=0,0    
    while(s<n):
        if(acc>n):
            acc-=s
            s+=1
        else:
            if(e<n):
                e+=1
                acc+=e
        if(acc==n):
            answer+=1
    return answer