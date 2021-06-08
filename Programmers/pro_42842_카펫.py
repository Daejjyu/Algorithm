def solution(brown, yellow):
    for h in range(3,2500):
        for w in range(h,2500):
            if((w-2)*(h-2)==yellow and h*w==brown+yellow):
                return [w,h]
