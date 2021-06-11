def solution(n):
    cnt = bin(n).count("1")
    for i in range(n+1,1000000+1):
        if(bin(i).count("1")==cnt):
            break        
    return i