def solution(prices):
    answer=[len(prices)-1-x for x in range(len(prices))]
    stack=[]
    for idx, elem in enumerate(prices):
        while(stack and stack[-1][1]>elem):
            i,j = stack.pop()
            answer[i]=idx-i
        stack.append([idx,elem])
    return answer