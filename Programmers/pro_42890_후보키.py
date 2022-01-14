from collections import deque
from itertools import combinations

def solution(relation):
    nRow = len(relation)
    nCol = len(relation[0])
    
    candidates = []
    for i in range(1,nCol+1):
        candidates +=combinations(range(nCol),i)
    
    uniqueness = []
    for keys in candidates:
        tmp=[item[key] for key in keys for item in relation]
        if len(set(tmp))==nRow:
            uniqueness.append(keys)
    minimality=set(uniqueness[:])
    for i in range(len(uniqueness)):
        for j in range(i+1,len(uniqueness)):
            if len(uniqueness[i])==len(set(uniqueness[i]) & (set(uniqueness[j]))): 
                minimality.discard(uniqueness[j])
    return len(minimality)