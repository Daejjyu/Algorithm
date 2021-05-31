def solution(num):
    loop=0
    while(loop<=500):
        if(num==1):
            return loop
        loop+=1
        if(num%2):
            num= num*3+1
        else:
            num/=2
    return -1