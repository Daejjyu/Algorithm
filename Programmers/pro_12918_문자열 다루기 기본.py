def solution(s):
    if(len(s)!=4 and len(s)!=6):
        return False
    for i in s:
        if('0'<=i<='9'):
            continue
        else:
            return False    
    return True