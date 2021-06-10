from collections import defaultdict
def solution(msg):    
    char_dict = defaultdict(int)
    for i in range(26):
        char_dict[chr(ord('A')+i)]=i+1
    dict_num=27
    answer = []
    idx=0
    while(idx<len(msg)):
        cur=msg[idx]
        prev = char_dict[cur]
        i=idx
        while(char_dict[cur]!=0):
            prev = char_dict[cur]
            i+=1
            if(i==len(msg)):
                idx+=1
                break
            cur+=msg[i]
        answer.append(prev)
        char_dict[cur]=dict_num
        dict_num+=1
        idx+=len(cur)-1
        if(len(cur)==1):
            break
    return answer