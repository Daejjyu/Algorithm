def solution(s):
    cntBinary,cntZero=0,0
    while(s!='1'):
        cntBinary+=1
        cntOne = s.count('1')
        cntZero += len(s)-cntOne
        s = bin(cntOne)[2:]        
    return [cntBinary,cntZero]