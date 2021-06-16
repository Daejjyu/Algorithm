def solution(board):
    W,H = len(board[0]),len(board)
    answer=max(board[0])
    for r in range(1,H):
        for c in range(1,W):
            if board[r][c]==1:
                board[r][c]=min(board[r-1][c],board[r][c-1],board[r-1][c-1])+1
                answer=max(answer,board[r][c])
    return answer**2