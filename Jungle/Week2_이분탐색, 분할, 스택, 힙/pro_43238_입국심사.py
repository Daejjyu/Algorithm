def solution(n, times):
    answer = 0
    lo=-1
    hi=1e18+1
    
    while(lo+1 <hi):
        mid = int((lo+hi)//2)
        sum1=0
        for i in times:
            sum1+= int(mid//i)
        if(sum1>=n):
            hi=mid #만족 시 hi이므로 hi반환
        else:
            lo=mid
    return hi