def getLast(numbers,target,cnt,acc):    
    if(cnt==len(numbers)):
        if(target==acc):
            return 1
        return 0
    else:
        return getLast(numbers,target,cnt+1,acc+numbers[cnt]) + getLast(numbers,target,cnt+1,acc-numbers[cnt])        
        
def solution(numbers, target):
    answer = 0
    answer += getLast(numbers,target,0,0)
    return answer