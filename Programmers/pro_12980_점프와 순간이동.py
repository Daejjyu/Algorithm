def solution(n):
    return bin(n).count('1')
    # answer=0
    # while(n):
    #     if(n%2):
    #         answer+=1
    #     n//=2
    # return answer