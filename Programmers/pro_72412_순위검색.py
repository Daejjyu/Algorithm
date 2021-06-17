from itertools import combinations
from collections import defaultdict
from bisect import bisect_left, bisect_right

def solution(info, query):
    info_dict=defaultdict(list)
    for line in info:
        line = line.split()
        num = int(line[-1])
        for i in range(1,len(line)):
            comb = list(combinations(line[:-1],i))
            for elem in comb:
                elem = '-'+''.join(elem)
                info_dict[elem].append(num)
        info_dict['-'].append(num)
        
    for key in info_dict.keys(): 
        info_dict[key].sort()

    answer = []
    for line in query:
        line = line.split(' ')
        num = int(line[-1])
        key = '-'
        for i in range(len(line)-1):
            if line[i]!='and' and line[i]!= '-':
                key+=line[i]
        arr = info_dict[key]
        answer.append(len(arr)-bisect_left(arr,num))
        
    return answer
