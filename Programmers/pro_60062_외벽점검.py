
from itertools import permutations
def solution(n, weak, dist):
    l = len(weak)
    answer = 0
    cand = []
    weakExtend = weak + [n+x for x in weak]    
    for i, start in enumerate(weak):
        for distArr in permutations(dist):
            pos = start
            cnt =1
            for num in distArr:
                pos+=num
                if pos<weakExtend[i+l-1]:
                    cnt+=1
                    pos = [x for x in weakExtend[i+1:i+l] if x>pos][0]
                else:
                    cand.append(cnt)
                    break
    return min(cand) if cand else -1