def gcd(a,b):
    while(b):
        r=a%b
        a=b
        b=r
    return a

def solution(n, m):
    num = gcd(n,m)
    return [num,n*m/num]