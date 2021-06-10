
def makeCharList(charList):
    for i in range(16):
        if(i<10):
            charList.append(str(i))
        else:
            charList.append(chr(ord("A")+i-10))
def baseN(num,base,charList):
        if(num==0):
            return "0"
        ret = ''
        while(num):
            ret+=charList[num%base]
            num//=base
        return ret[::-1]
    
def solution(n, t, m, p):
    charList=[]
    makeCharList(charList)    
    answer = ''
    cur=0
    turn=0
    while(len(answer)<t):
        cur_char = baseN(cur,n,charList)
        for i in range(len(cur_char)):
            if((p-1)==(turn%m)):
                answer += cur_char[i]
            turn+=1
        cur+=1        
    return answer[:t]
