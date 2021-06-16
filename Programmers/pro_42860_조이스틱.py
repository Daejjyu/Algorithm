def findPos(idx,cur,name,right):
    move = 0
    while(cur[idx]==name[idx]):
        idx+=right
        move+=1
        if(idx<0):
            idx=len(cur)-1
        if(idx>=len(cur)):
            idx = 0
    return [idx,move]

def solution(name):
    cur=["A"]*len(name)
    control = 0
    idx=0
    while(''.join(cur)!=name):
        r, moveR = findPos(idx,cur,name,1)
        l, moveL = findPos(idx,cur,name,-1)
        idx,moveNext = [r,moveR] if moveR<=moveL else [l,moveL]
        upControl = min(ord(name[idx])-ord("A"),1+ord("Z")-ord(name[idx]))
        control+=(moveNext+upControl)
        cur[idx]=name[idx]
        
    return control
