from collections import defaultdict
from itertools import combinations

def solution(orders, course):
    menu_dict = defaultdict(int)
    max_cnt =defaultdict(int)
    for order in orders:
        for i in range(1,len(order)+1):
            comb = list(combinations(order,i))
            for elem in comb:
                elem = ''.join(sorted(elem))
                for k in course:
                    if len(elem)==k:
                        menu_dict[elem]+=1
                        max_cnt[str(k)]=max(max_cnt[str(k)],menu_dict[elem])
                        
    answer = []
    for elem, cnt in menu_dict.items():
        l = len(elem)
        if(l<2 or cnt<2):
            continue
        maxN = max_cnt[str(l)]
        if(cnt==maxN):
            answer.append(elem)
    return sorted(answer)