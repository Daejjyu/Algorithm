def findLeft(idx,cur,name):
    move = 0
    while(cur[idx]!=name[idx]):
        idx-=1
        move+=1
        if(idx<0):
            idx=len(cur)-1
        if(move>100):
            break
    return [idx,move]

def findRight(idx,cur,name):
    move=-1
    for i in range(idx,len(cur)):
        move+=1
        if(cur[i]!=name[i]):
            return [i,move]
    for i in range(0,idx):
        move+=1
        if(cur[i]!=name[i]):
            return [i,move]
    return [idx,move]

def solution(name):
    cur=["A"]*len(name)
    control = 0
    idx=0
    while(''.join(cur)!=name):
        r, moveR = findRight(idx,cur,name)
        l, moveL = findLeft(idx,cur,name)
        idx,moveNext = [r,moveR] if moveR<=moveL else [l,moveL]
        upControl = min(ord(name[idx])-ord("A"),1+ord("Z")-ord(name[idx]))
        control+=(moveNext+upControl)
        cur[idx]=name[idx]
        
    return control