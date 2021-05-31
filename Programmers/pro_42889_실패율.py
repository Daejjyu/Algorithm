def solution(N, stages):
    #idx,클리어x수,도달수
    curStage = [0]*(N+1)
    for i in stages:
        curStage[i-1]+=1
        
    answer = []
    sum = 0
    for idx,num in enumerate(curStage):
        if(idx==N):
            break
        if(num==0):
            answer.append((0,idx+1))
        else:
            answer.append((num/(len(stages)-sum),idx+1))
        sum+=num
    answer = [idx for score,idx in sorted(answer,key=lambda x:(-x[0],x[1]))]
    return answer