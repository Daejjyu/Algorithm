def deleteElem(arr):
    Ncol = len(arr[0])
    Nrow = len(arr)
    for c in range(Ncol):
        for r in range(Nrow-1,0,-1):
            if(arr[r][c]=='0'):
                for k in range(1,r+1):
                    if(arr[r-k][c]!='0'):
                        arr[r][c]=arr[r-k][c]
                        arr[r-k][c]='0'
                        break
            
def solution(m, n, board):
    board = [list(x) for x in board]
    Nrow=m
    Ncol=n
    # 각 칸에 대해서 우측, 밑, 우측밑 확인
    nextPos = [[0,0],[1,0],[0,1],[1,1]]
    while(1):
        visited=[[0 for _ in range(Ncol)]for _ in range(Nrow)]
        isChanged=False
        nextBoard = [x[:] for x in board]
        for r in range(Nrow-1):
            for c in range(Ncol-1):
                cur = board[r][c]
                if(board[r][c]=='0'):
                    continue
                flag=True
                for i,j in nextPos:
                    if(board[r+i][c+j]!=cur):
                        flag=False
                        break
                if(flag):
                    isChanged=True
                    for i,j in nextPos:
                        nextBoard[r+i][c+j]='0'
        if(isChanged==False):
            break
        deleteElem(nextBoard)
        board = nextBoard
    answer=0
    for i in board:
        for j in i:
            if j=='0':
                answer+=1
    return answer
