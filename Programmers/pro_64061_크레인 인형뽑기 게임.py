def solution(board, moves):
    #board[height][idx]
    stack = []
    answer = 0
    
    size = len(board[0])
    isFin = [0]*size
    
    for i in moves:
        if(isFin[i-1]==0):
            for j in range(size):
                if(j==size-1):
                    isFin[i-1]=1
                    
                cur = board[j][i-1]
                if(cur>0):
                    board[j][i-1]=0
                    if(stack and stack[-1]==cur):
                        answer+=2
                        stack.pop()
                    else:
                        stack.append(cur)
                    break                
    return answer