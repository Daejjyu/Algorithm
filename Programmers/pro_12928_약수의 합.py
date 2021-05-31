def solution(n):
    return n + sum([x for x in range(1,n//2 +1) if n%x==0])