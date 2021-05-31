def solution(lottos, win_nums):
    answer = []
    zeroNum=0
    correctNum=0
    for i in lottos:
        if(i==0):
            zeroNum+=1
        else:
            if i in win_nums:
                correctNum+=1
    answer.append(min(6,7-(correctNum+zeroNum)))
    answer.append(min(6,7-correctNum))
    return answer