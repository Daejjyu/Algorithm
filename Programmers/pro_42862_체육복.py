def solution(n, lost, reserve):
    clothes = [1]*n
    for i in lost:
        clothes[i-1]=0
        
    for j in range(len(reserve)):
        cur = reserve[j]
        if(clothes[cur-1]==0):#self
            clothes[cur-1]=1
            reserve[j]=1e9
            
    reserve.sort()
    for j in reserve:
        if(j==1e9):
            break
        if(j>=2 and clothes[j-2]==0):#left
            clothes[j-2]=1
        elif(j<=n-1 and clothes[j]==0):#right
            clothes[j]=1
    return sum(clothes)