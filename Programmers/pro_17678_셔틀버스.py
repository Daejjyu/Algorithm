from collections import deque

def toSecond(strTime):
    h,m=strTime.split(":")
    return int(h)*60+int(m)

def toStrTime(sec):
    h="0"+str(sec//60)
    m="0"+str(sec%60)
    return h[-2:]+":"+m[-2:]

def solution(n, t, m, timetable):
    timetable = deque(sorted([toSecond(x) for x in timetable]))
    start = 9*60
    answer = min(min(timetable)-1,start+t*(n-1))
    for i in range(start,start+t*n,t):
        left=m
        while(left and timetable and timetable[0]<=i):
            left-=1
            timetable.popleft()
            if(left==1 and timetable):
                answer=max(timetable[0]-1,answer)
        if(left):
            answer=max(answer,i)
        
    return toStrTime(answer)