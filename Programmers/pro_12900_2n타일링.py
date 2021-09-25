def solution(n):
    MOD = 1000000007
    a,b=0,1
    for i in range(n):
        a,b = b,(a+b)%MOD        
    return b%MOD