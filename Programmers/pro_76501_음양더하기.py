def solution(absolutes, signs):
    answer=0
    for i,j in zip(absolutes,signs):
        if(j==True):
            answer += i
        else:
            answer-=i
    return answer