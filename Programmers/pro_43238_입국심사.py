def solution(n, times):
    answer = 0
    lo = -1
    hi = int(1e19)
    while(lo+1<hi):
        mid = (hi+lo)//2
        cnt=0
        for i in times:
            cnt+=mid//i
            if(cnt>n):
                break
        if(cnt>=n): 
            hi=mid
        else:
            lo=mid      
    return hi