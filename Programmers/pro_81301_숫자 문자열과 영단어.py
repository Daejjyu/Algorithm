def solution(s):
    NUMBER = {'zero':'0','one':'1','two':'2','three':'3','four':'4',
              'five':'5','six':'6','seven':'7','eight':'8','nine':'9'}
    answer = ''
    numStr=''
    for i in s:
        if '0'<=i<='9':
            answer+=i
        else:
            numStr+=i
            if numStr in NUMBER:
                answer+=NUMBER[numStr]
                numStr=''        
    return int(answer)