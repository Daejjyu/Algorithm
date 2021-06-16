def solution(n):
    if n<=3:
        return '124'[n-1]
    else:
        return solution((n-1) //3) + '124'[(n-1)%3] 