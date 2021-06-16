dict_sharp = {"C#":"0","D#":"1","E#":"2","F#":"3","G#":"4","A#":"5"}
def imputeSharp(code):
    code = list(code)
    for i in range(len(code)):
        if code[i]=='#':
            sharp = code[i-1]+code[i]
            code[i-1]=dict_sharp[sharp]
            code[i]=''
    return ''.join(code)

def getInfos(info):
    s,e,name,code = info.split(',')
    s = splitTime(s)
    e = splitTime(e)
    return [e-s,name,imputeSharp(code)]

def splitTime(timeStr):
    timeStr = timeStr.split(":")
    return int(timeStr[0])*60+int(timeStr[1])

def solution(m, musicinfos):    
    #조건이 일치하는 음악이 없을 때에는 “(None)”을 반환한다.
    answer = '(None)'
    max_len=0
    m=imputeSharp(m)
    for i in musicinfos:
        playTime,name,code=getInfos(i)
        #음악 길이보다 재생된 시간이 짧을 때는 처음부터 재생 시간만큼만 재생된다.
        code = code*(playTime//len(code)) + code[:playTime%len(code)]
        if m in code:
            #조건이 일치하는 음악이 여러 개일 때에는 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환한다.
            if(max_len<playTime):
                max_len=playTime
                answer=name
    return answer