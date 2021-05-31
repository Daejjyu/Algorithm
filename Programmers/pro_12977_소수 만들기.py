isPrime = [1]*3001
def eratos(): #방법 1 공간을 써서 시간을 절약
    isPrime[0]=0
    isPrime[1]=0
    for i in range(2,len(isPrime)):
        if(isPrime[i]==1):
            j = 2
            while(i*j<len(isPrime)):
                isPrime[i*j]=0
                j+=1
                
def eratos2(num): #방법 2 시간을 써서 공간을 절약
    i=2
    while(i*i<=num):
        if(num%i==0):
            return False
        i+=1
    return True

def solution(nums):
    eratos()
    candidates = set()
    
    lenNum = len(nums)
    answer = 0
    for i in range(lenNum):
        for j in range(i+1,lenNum):
            for k in range(j+1,lenNum):
                # if(isPrime[(nums[i]+nums[j]+nums[k])]):
                    # answer+=1
                if(eratos2(nums[i]+nums[j]+nums[k])):
                    answer+=1
    
    return answer