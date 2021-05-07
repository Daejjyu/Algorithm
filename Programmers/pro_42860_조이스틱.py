# https://velog.io/@syc1013/%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B4%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%A1%B0%EC%9D%B4%EC%8A%A4%ED%8B%B1
def solution(name):
    def topDown(answer,c):
        answer += min((ord(c) - 65, 90-ord(c)+1))
        return answer
    def leftRight(wordToChange, name, i):
        moveR=1
        moveL=1
        #right
        while True:            
            if i+moveR > len(name)-1:
                indexR = i+moveR - len(name)
            else: 
                indexR = i+moveR
            if wordToChange[indexR] != name[indexR]:
                break
            moveR+=1
        #left
        while True:            
            if i-moveL < 0:
                indexL = i-moveL + len(name)
            else: 
                indexL = i-moveL
            if wordToChange[indexL] != name[indexL]:
                break
            moveL+=1
        
        if moveR <= moveL:
            return moveR, indexR
        else:
            return moveL, indexL
        
    answer = 0
    cursor = 0
    wordToChange = ['A']*len(name)
    name=list(name)
    #topDown
    for c in name:
        answer = topDown(answer, c)
    #leftRight
    while wordToChange != name:
        #change first letter
        wordToChange[cursor] = name[cursor]
        #start move
        move, cursor = leftRight(wordToChange, name, cursor)
        wordToChange[cursor] = name[cursor]
        answer+= move
    return answer