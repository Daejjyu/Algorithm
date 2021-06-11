def gcd(a,b):
    while(b):
        r=a%b
        a=b
        b=r
    return a
def solution(arr):
    for i in range(len(arr)):
        arr[i]=(arr[i]*arr[i-1])//gcd(arr[i],arr[i-1])
    return arr[-1]
