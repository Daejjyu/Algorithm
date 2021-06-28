def solution(s):
    L = len(s)
    answer = 1
    for l in range(2,L+1):
        for i in range(L):
            if(i+l>L):
                break
            cur = s[i:i+l]
            if(cur==cur[::-1]):
                answer=l
                break
    return answer