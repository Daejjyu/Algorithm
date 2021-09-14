from collections import defaultdict
def solution(weights, head2head):    
    result = []
    for i, record in enumerate(head2head):
        number = i+1
        cnt_win=0
        cnt_heavy=0
        cnt_play=0
        weight_self = weights[i]
        for j, char in enumerate(record):
            if(char=='W' or char=='L'):
                cnt_play+=1
            if(char =='W'):
                cnt_win+=1
                if(weight_self<weights[j]):
                    cnt_heavy+=1        
        win_rate = cnt_win/cnt_play*100 if cnt_play else 0
        result.append([win_rate,cnt_heavy,weight_self,number])
    answer = list(map(lambda x:x[3],sorted(result, key = lambda x: (-x[0],-x[1],-x[2],x[3]))))    
    return answer