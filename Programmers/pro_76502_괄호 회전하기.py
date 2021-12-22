def solution(s):
    openList = ["(","{","["]
    close_dict = {"(":")","{":"}","[":"]"}
    def check(a,b,s,stack):
        for j in range(a,b):
            if(s[j] in openList):
                stack.append(s[j])
            else:
                if stack and close_dict[stack[-1]]==s[j]:
                    stack.pop()
                    continue
                return False
        return True

    answer = 0
    for i in range(len(s)):
        stack = []   
        if(check(i,len(s),s,stack) and check(0,i,s,stack) and not stack):
            answer+=1        
    return answer