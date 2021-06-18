def solution(n, times):
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
    return hi # 최대값(조건 만족 값) 중 최소값