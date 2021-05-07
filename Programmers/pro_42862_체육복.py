def solution(n, lost, reserve):
    answer = 0
    arr = [1]*(n+1)
    arr[0] = 0
    for num in lost:
        arr[num]-=1
        
    reserve.sort()
    
    # 자신 -> 왼쪽lost -> 오른쪽lost
    for i in range(len(reserve)):
        if(arr[reserve[i]]==0):
            arr[reserve[i]]+=1
            reserve[i]=-1
            
    for num in reserve:
        if(num==-1):
            continue
        if(arr[num]==0):
            arr[num]+=1
        elif(num > 1 and arr[num-1]==0):
            arr[num-1]+=1
        elif(num < n and arr[num+1]==0):
            arr[num+1]+=1
            
    return sum(arr)