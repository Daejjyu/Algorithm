def getGrade(score):
    GRADE = {'A':90,'B':80,'C':70,'D':50}
    for i, j in GRADE.items():
        if score>=j:
            return i
    return 'F'

def solution(scores):
    answer = ''
    N = len(scores)
    scores = list(map(list,zip(*scores)))
    for i in range(N):
        flag = True if max(scores[i])==scores[i][i] or min(scores[i])==scores[i][i] else False
        sumScore=0
        for j in range(N):
            sumScore+=scores[i][j]
            if i!=j and scores[i][i]==scores[i][j]:
                flag=False        
        avg = (sumScore-scores[i][i])/(N-flag) if flag else sumScore/N
        answer+=getGrade(avg)
    return answer