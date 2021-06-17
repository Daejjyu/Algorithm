def solution(distance, rocks, n):
    rocks+=[0,distance]
    rocks.sort()
    lo = -1
    hi = distance+1
    while(lo+1<hi):
        mid = (lo+hi)//2
        cnt,prev=0,0
        for i in range(1,len(rocks)):
            if(rocks[i]-prev < mid):
                cnt+=1
            else:
                prev=rocks[i]
            if(cnt>n):
                break
        if(cnt<=n):
            lo=mid
        else:
            hi=mid
    return lo