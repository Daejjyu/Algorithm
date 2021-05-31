def calPos(num):    # {*:-1} {0:-2} {#:-3} 매핑
    if(num<=0):
        num= -num + 9
    col = num%3
    if(col ==0):
        col=3
    row = (num-1)//3
    return col*10+row

def calDist(a,b):    
    return abs(a//10-b//10) + abs(a%10-b%10)    

def solution(numbers, hand):
    leftNum = [1,4,7]
    rightNum = [3,6,9]
    
    curLeft = -1 # {*:-1}
    curRight = -3 # {#:-3}
    
    answer = ''
    for i in numbers:
        if(i==0):
            i=-2 # {0:-2}
            
        isRight = True
        if i in leftNum:
            isRight=False
        elif i in rightNum:
            isRight=True
        else:
            leftDist = calDist(calPos(curLeft),calPos(i))
            rightDist = calDist(calPos(curRight),calPos(i))
            if(leftDist<rightDist or (leftDist==rightDist and hand=='left')):
                isRight=False
        if(isRight):
            answer+='R'
            curRight=i
        else:
            answer+='L'
            curLeft=i
    return answer