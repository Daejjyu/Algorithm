def solution(n,a,b):
    answer = 1
    while(1):
        nextA = max(1,(a+1)//2)
        nextB = max(1,(b+1)//2)
        if(nextA==nextB):
            return answer
        a=nextA
        b=nextB
        answer+=1
    return answer
# 12 34 56 78 910....
# 1   2  3  4  5 
# (n+1) %2 = 현재 집단,다음 번호
# 현재 집단이 같으면 끝
# 아니면 다음 번호로 진행