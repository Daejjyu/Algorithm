def solution(left, right):
    answer = 0
    for i in range(left,right+1):
        if(int(i**0.5)==i**0.5): # 제곱근을 가지면 홀수
            answer-=i
        else:
            answer+=i
    return answer