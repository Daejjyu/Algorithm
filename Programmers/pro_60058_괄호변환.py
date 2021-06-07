def isBalanced(p):
    cnt=0
    for i in p:
        if(i=='('):
            cnt+=1
        elif(i==')'):
        	cnt-=1
        if(cnt<0):
            return False
    return True
def stepTwo(p):
    cnt=0
    for i in range(len(p)):
        if(p[i]=='('):
            cnt+=1
        elif(p[i]==')'):
        	cnt-=1
        if (cnt==0):
            u=p[:i+1]
            v=p[i+1:]
            break
    return u,v
#3.
def solution(p):
	answer=''
    #1.
	if(p==''):
		return p
    #2.
	u,v=stepTwo(p)
	if(isBalanced(u)):
		return u+solution(v)
    #4.
	else:
		temp = '('
		temp +=solution(v)
		temp +=')'
		for i in range(1,len(u)-1):
			if(u[i]=='('):
				temp += ')'
			else:
				temp +='('        
		return temp
	return answer