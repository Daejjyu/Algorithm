function solution(board, moves) {
    const size = board.length
    const stack = []

    let answer = 0;
    moves.forEach((v, i) => {
        let col = v - 1
        for (let r = 0; r < size; r++) {
            let cur = board[r][col]
            if (cur > 0) {
                let len = stack.length
                if (len > 0 && stack[len - 1] == cur) {
                    stack.pop()
                    answer += 2
                } else
                    stack.push(board[r][col])
                board[r][col] = 0
                break
            }
        }
    })
    return answer;
}