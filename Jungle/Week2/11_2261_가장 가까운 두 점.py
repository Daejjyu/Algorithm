# http://www.grantjenks.com/docs/sortedcontainers/sortedlist.html?highlight=sortedlist
import sys
import math
from sortedcontainers import SortedList

def dist(a,b):
    ret=0
    ret = (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1])
    return ret

N = int(sys.stdin.readline())

pos = []
for i in range(N):
    x, y = map(int,sys.stdin.readline().split())
    pos.append([x,y])
pos.sort(key=lambda x:(x[0],x[1]))

candidate = SortedList([[pos[0][1],pos[0][0]],[pos[1][1],pos[1][0]]])# y,x
ans = dist(pos[0],pos[1])
start = 0
for i in range(2,N):
    cur = pos[i]
    while(start < i):
        cmp_value = pos[start]
        cmp_x = cur[0]-cmp_value[0]
        if(cmp_x*cmp_x>ans):
            candidate.remove([cmp_value[1],cmp_value[0]]) # y, x
            start+=1
        else:
            break
    if(candidate):
        y_range =  int(math.sqrt(ans))+1
        lo=0
        hi=len(candidate)
        while(lo+1<hi):
            mid = int((lo+hi)/2)
            if(candidate[mid][0]>=cur[1]-y_range):
                lo = mid
            else:
                hi = mid
        lower_idx=lo
        lo = 0
        hi = len(candidate)
        while (lo + 1 < hi):
            mid = int((lo + hi) / 2)
            if (candidate[mid][0] <= cur[1] + y_range):
                hi = mid
            else:
                lo = mid
        upper_idx = hi
        for i in range(lower_idx-1,upper_idx+1):
            if(i<0):
                continue
            if(i>=len(candidate)):
                break
            d = dist(cur,[candidate[i][1],candidate[i][0]])
            ans=min(ans,d)
    candidate.add([cur[1],cur[0]])
print(ans)


