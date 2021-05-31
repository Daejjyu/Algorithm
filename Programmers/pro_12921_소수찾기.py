isPrime =[1]*1000001
def eratos():
    isPrime[0]=0
    isPrime[1]=0
    for i in range(2,1000000):
        if(isPrime[i]):
            j=2
            while(i*j<=1000000):
                isPrime[i*j]=0
                j+=1    
    
def solution(n):
    eratos()
    answer=0
    
    for i in range(2,n+1):
        if(isPrime[i]):
            answer += 1
    return answer