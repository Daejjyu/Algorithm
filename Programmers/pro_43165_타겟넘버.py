def getTarget(numbers,target,cnt,acc):    
    if(cnt==len(numbers)):
        if(target==acc):
            return 1
        return 0
    else:
        return (getTarget(numbers,target,cnt+1,acc+numbers[cnt])
                + getTarget(numbers,target,cnt+1,acc-numbers[cnt]))
        
def solution(numbers, target):
    return getTarget(numbers,target,0,0)