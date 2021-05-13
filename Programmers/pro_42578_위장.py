def solution(clothes):
    from collections import Counter
    from functools import reduce
    
    cnt = Counter([kind for name, kind in clothes])
    answer = reduce(lambda acc,cur: acc *(cur+1),cnt.values(),1)-1
    return answer