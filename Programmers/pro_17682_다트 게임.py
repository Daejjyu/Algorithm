def solution(dartResult):
    stack = []
    cur =""
    for i in dartResult:
        if(i=="*"):
            if(len(stack)>=2):
                stack[-2]*=2
            if(len(stack)>=1):
                stack[-1]*=2
        elif(i=="#"):
            if(stack and stack[-1]>0):
                stack[-1]*=-1
        elif(i.isdigit()):
            cur+=i
        else:
            stack.append(int(cur))
            cur=""
            if(i=="S"):
                continue
            if(i=="D"):
                stack[-1]**=2
            if(i=="T"):
                stack[-1]**=3      
       
    return sum(stack)