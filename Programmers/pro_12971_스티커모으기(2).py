def solution(sticker):
    L = len(sticker)
    dp1 = [0]*L
    dp2 = [0]*L
    
    dp1[0]=sticker[0]
    if(L>1):
        dp2[0]=sticker[1]
        dp1[1]=sticker[1]
    if(L>2):
        dp1[2]=sticker[0] + sticker[2]
        dp2[1]=sticker[2]
    if(L>3):
        dp2[2]=sticker[1] + sticker[3]
    
    for i in range(3,L-1):
        dp1[i] = sticker[i] + max(dp1[i-2],dp1[i-3])
    for i in range(4,L):
        dp2[i-1] = sticker[i] + max(dp2[i-3],dp2[i-4])
    
    # 1번째가 안들어갈 때 -> [2, 마지막]에서 최고값 //dp1
    # 마지막이 안들어갈 떄 -> [1, 마지막-1]에서 최고값 //dp2
    return max(max(dp1),max(dp2))