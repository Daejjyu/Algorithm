import math
def solution(n, stations, w):
    answer = 0
    rangeW = 2*w+1
    cur=1
    for i in stations:
        s,e = i-w, min(i+w,n)
        if(s > cur):
            answer += math.ceil((s-cur)/rangeW)
        cur=e+1
    if(cur <= n):
        answer += math.ceil((n+1-cur)/rangeW)
    return answer