def changeChar(s):
    #사실 E#도 있찌롱...
    dict_change={"C#":"0","D#":"1","F#":"2","G#":"3","A#":"4","E#":"5"}
    changeS = list(s)
    for i in range(len(changeS)):
        if changeS[i]=="#":
            temp = changeS[i-1]+changeS[i]
            changeS[i-1] = dict_change[temp]
            changeS[i]=''
    return ''.join(changeS)

def solution(m, musicinfos):
    #조건이 일치하는 음악이 없을 때에는 “(None)”을 반환한다.
    answer = '(None)'
    max_len = 0
    m = changeChar(m)
    for i in range(len(musicinfos)):        
        temp = musicinfos[i].split(',')
        temp[3] =changeChar(temp[3])
        start = temp[0].split(':')
        end = temp[1].split(':')
        playTime = (int(end[0])-int(start[0]))*60 + int(end[1])-int(start[1])        
        #음악 길이보다 재생된 시간이 짧을 때는 처음부터 재생 시간만큼만 재생된다
        temp[3]=temp[3][:min(playTime,len(temp[3]))]
        if m in temp[3]*playTime:
            #조건이 일치하는 음악이 여러 개일 때에는 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환한다. 
            if(max_len<playTime):
                answer = temp[2]
                max_len=playTime
    return answer
