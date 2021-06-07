def calPriority(split, priority):
	stack=split
	for i in priority:
		split = stack
		stack=[]
		j=0
		while(j<len(split)):
			if(i==split[j]):
				if(i=='*'):
					stack[-1]*=split[j+1]
				elif(i=='-'):
					stack[-1]-=split[j+1]
				elif(i=='+'):  
					stack[-1]+=split[j+1]
				j+=1
			else:
				stack.append(split[j])
			j+=1
	return abs(stack[0])
    
def solution(expression):
    priority=['-+*','-*+','+-*','+*-','*+-','*-+']
    split = []
    cur=''
    for i in expression:
        if(i in '-+*'):
            split+=[int(cur),i]
            cur=''
        else:
        	cur+=i
    split.append(int(cur))
        
    answer = 0
    for i in range(6):
    	answer=max(calPriority(split, priority[i]),answer)
    return answer