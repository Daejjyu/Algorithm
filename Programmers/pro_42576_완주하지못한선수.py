from collections import defaultdict
def solution(participant, completion):
    dict_cnt = defaultdict(int)
    for i in participant:
        dict_cnt[i]+=1
    for i in completion:
        dict_cnt[i]-=1
    for i in participant:
        if(dict_cnt[i]==1):
            return i
    answer = ''
    return answer