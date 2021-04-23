string = str(input())

stack = []
possible=True
for i in string:
    flag=True
    if(possible==False):
        break
    if(i == '(' or i == '['):
        stack.append(i)
    elif(i==')'):
        while(1):
            if(flag==False):
                break
            if (possible == False):
                break
            if(len(stack)==0):
                possible = False
                break
            top = stack[-1]
            if(top == '['):
                possible=False
                break
            if(top == '('):
                stack.pop()
                stack.append(2)
                break
            temp=0
            if(type(top)==int):
                while(1):
                    if (possible == False):
                        break
                    temp += top
                    stack.pop()
                    if(len(stack)==0):
                        possible=False
                        break
                    top = stack[-1]

                    if(top == '['):
                        possible=False
                        break
                    elif(top == '('):
                        temp*=2
                        stack.pop()
                        stack.append(temp)
                        flag=False
                        break
    elif(i==']'):
        while(1):
            if(flag==False):
                break
            if (possible == False):
                break
            if(len(stack)==0):
                possible = False
                break
            top = stack[-1]
            if(top == '('):
                possible=False
                break
            if(top == '['):
                stack.pop()
                stack.append(3)
                break
            temp=0
            if(type(top)==int):
                while(1):
                    if (possible == False):
                        break
                    temp += top
                    stack.pop()
                    if(len(stack)==0):
                        possible=False
                        break
                    top = stack[-1]

                    if(top == '('):
                        possible=False
                        break
                    elif(top == '['):
                        temp*=3
                        stack.pop()
                        stack.append(temp)
                        flag=False
                        break




for i in stack: # case only ( or [
    if(i=='(' or i=='['):
        possible=False
        break
if(possible):
    print(sum(stack))
else:
    print(0)