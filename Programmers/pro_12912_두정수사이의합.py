def solution(a, b):
    answer=0
    s= min(a,b)
    e = max(a,b)
    while(s<=e):
        answer+=s
        s+=1
    return answer