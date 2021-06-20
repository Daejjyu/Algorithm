function solution(board) {
    const [R, C] = [board.length, board[0].length]
    let answer = 0
    if (C === undefined) {
        for (let i = 0; i < R; i++) {
            if (board[i] == 1) {
                answer = 1
                break
            }
        }
    }
    for (let i = 0; i < R; i++) {
        if (board[0][i] == 1) {
            answer = 1
            break
        }
    }
    for (let r = 1; r < R; r++) {
        for (let c = 1; c < C; c++) {
            if (board[r][c] == 1)
                board[r][c] = 1 + Math.min(board[r - 1][c], board[r - 1][c - 1], board[r][c - 1])
            answer = Math.max(board[r][c], answer)
        }
    }
    return Math.pow(answer, 2)
}
