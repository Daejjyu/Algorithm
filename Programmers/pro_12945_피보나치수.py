def solution(n):
    fibo=[0]+[1]+[0]*n
    for i in range(2,n+1):
        fibo[i]=fibo[i-1]+fibo[i-2]
    return fibo[n]%1234567