def solution(s, n):
    answer=''
    for i in s:
        if('a'<=i<='z'):
            i=chr(ord('a')+(ord(i)-ord('a')+n)%26)
        if('A'<=i<='Z'):
            i=chr(ord('A')+(ord(i)-ord('A')+n)%26)
        answer+=i
    return answer