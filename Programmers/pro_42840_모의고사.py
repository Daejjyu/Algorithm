def solution(answers):
    correctNum = [0,0,0]
    candidate = [[1,2,3,4,5],[2,1,2,3,2,4,2,5],[3,3,1,1,2,2,4,4,5,5]]
        
    for i in range(len(correctNum)):
        for j in range(len(answers)):
            if(answers[j]==candidate[i][j%len(candidate[i])]):
                correctNum[i]+=1
    answer = []
    for i in range(3):
        if(max(correctNum)==correctNum[i]):
            answer.append(i+1)
    return answer