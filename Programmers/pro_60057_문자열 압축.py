def solution(s):
    answer = len(s)    
    for l in range(1,len(s)//2+2):
        temp = ''
        idx, cnt = 0, 0
        while(idx<len(s)):
            cur = s[idx:idx+l]
            if cur == s[idx+l:idx+2*l]:
                cnt+=1
            else:
                if(cnt>0):
                    temp+=str(cnt+1)
                    cnt=0
                temp+=cur
            idx+=l
        answer=min(answer,len(temp))
    return answer