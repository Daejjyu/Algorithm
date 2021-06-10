def solution(s):
    stack = []
    for i in s:
        if(i=='('):
            stack.append(i)
        elif(not stack):
            stack.append("No!!")
            break
        else:
            if(stack[-1]!='('):
                break
            stack.pop()      
    return False if stack else True