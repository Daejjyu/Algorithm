
def solution(number, k):
    number = list(map(int,number))
    left=k
    cur_idx =0
    ran = []
    while(cur_idx+left<len(number) and left>0):
        if(number[cur_idx]==9): #시간 개선
            cur_idx+=1
            continue
        for i in range(cur_idx+1,cur_idx+left+1):
            if(number[cur_idx]<number[i]):
                ran.append((cur_idx,i))
                left-=(i-cur_idx)
                cur_idx=i-1
                break
        cur_idx+=1
        
    l = len(number)
    for s,e in ran:
        for i in range(s,e):
            number[i]="a"
    number = ''.join(map(str,number))
    number = number.replace("a",'')
    if(left>0):
        number = number[:l-left]
    return number