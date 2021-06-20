function solution(m, n, board) {
    var boardTrans = [...board[0]].map(function (col, i) {
        return board.map(function (row) {
            return row[i]
        })
    });
    let [R, C] = [boardTrans[0].length, boardTrans.length]
    let cnt = 0
    let answer = 0;
    while (true) {
        //check
        let deleteSet = new Set()
        for (let c = 0; c < C - 1; c++) {
            for (let r = 0; r < R - 1; r++) {
                let cur = boardTrans[c][r]
                if (cur === "0")
                    continue
                if (boardTrans[c + 1][r] == cur && boardTrans[c][r + 1] == cur && boardTrans[c + 1][r + 1] == cur) {
                    deleteSet.add(100 * c + r)
                    deleteSet.add(100 * (c + 1) + r)
                    deleteSet.add(100 * c + r + 1)
                    deleteSet.add(100 * (c + 1) + r + 1)
                }
            }
        }
        deleteSet = [...deleteSet]
        let deleteLen = deleteSet.length
        //boom        
        if (deleteLen == 0)
            break
        answer += deleteLen
        for (let j = 0; j < deleteLen; j++) {
            let [c, r] = [deleteSet[j] / 100, deleteSet[j] % 100]
            boardTrans[parseInt(c)][parseInt(r)] = ''
        }
        for (let c = 0; c < C; c++) {
            boardTrans[c] = [...("0".repeat(m) + boardTrans[c].join("")).slice(-m)]
        }
    }
    return answer;
}

