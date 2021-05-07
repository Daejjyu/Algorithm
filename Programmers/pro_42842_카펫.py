def solution(brown, yellow):
    for x in range(brown//2):
        for y in range(brown//2):
            if(x*y==brown+yellow and 2*x+2*y-4==brown):
                if(x>y):
                    return [x,y]
                else:
                    return [y,x]