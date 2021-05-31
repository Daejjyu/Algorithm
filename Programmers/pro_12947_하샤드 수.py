def solution(x):    
    return False if x % sum(list(map(int,str(x)))) else True