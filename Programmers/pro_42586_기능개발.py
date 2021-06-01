def solution(progresses, speeds):
    answer = [0]
    day=0
    for i,j in zip(progresses,speeds):
        if(i+j*day>=100):            
            answer[-1]+=1
        else:
            day = (100-i)//j if (100-i)%j ==0 else ((100-i)//j)+1
            answer.append(1)
    return answer if answer[0]!=0 else answer[1:]