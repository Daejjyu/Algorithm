# https://bladejun.tistory.com/153
def solution(s):
    answer = []
    for numStr in s:
        stk=[]
        targetCnt=0
        for char in numStr:
            if char=='0' and stk[-2:] == ['1','1']:
                targetCnt+=1
                stk.pop()
                stk.pop()
            else:
                stk.append(char)
        if(targetCnt==0):
            answer.append(numStr)
        else:
            result = ''
            while stk and stk[-1]=='1':
                result+=stk.pop()
            while targetCnt:
                result = '110'+result
                targetCnt-=1
            answer.append(''.join(stk)+result)
    return answer