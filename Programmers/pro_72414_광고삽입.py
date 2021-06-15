#https://dev-note-97.tistory.com/156

def toSecond(timeStr):
    h,m,s = timeStr.split(":")
    return int(h)*3600 +int(m)*60 +int(s)
def timeToStr(time):
    h = "0"+str(time//3600)
    m = "0"+str((time%3600)//60)
    s = "0"+str(time%60)
    return ':'.join([h[-2:],m[-2:],s[-2:]])
def solution(play_time, adv_time, logs):
    play_time,adv_time = toSecond(play_time),toSecond(adv_time)
    logs = [[toSecond(y),toSecond(z)] for y,z in [x.split('-') for x in logs]]
    viewNum = [0]*(play_time+1)
    for i,j in logs:
        viewNum[i]+=1
        viewNum[j]-=1
    for i in range(1,play_time): # viewNum at time
        viewNum[i]=viewNum[i]+viewNum[i-1]
    for i in range(1,play_time): # cumulative sum
        viewNum[i]=viewNum[i]+viewNum[i-1]
    answer,max_view = 0, 0
    for i in range(adv_time-1,play_time):
        if(viewNum[i]-viewNum[i-adv_time]>max_view):
            max_view = viewNum[i]-viewNum[i-adv_time]
            answer = i-adv_time+1
    return timeToStr(answer)
