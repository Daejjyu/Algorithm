function solution(block, board) {
    const SIZE = board.length

    const sumRow = (arr, r) => {
        let ret = 0
        let L = arr[0].length
        for (let i = 0; i < L; i++) {
            ret += arr[r][i]
        }
        return ret
    }

    const isPop = (r, height, shape) => {
        let ret = 0
        for (let i = 0; i < height; i++) {
            if (sumRow(board, r + i) + sumRow(shape, i) == SIZE)
                ret += 1
        }
        return ret
    }

    let answer = 0;

    const checkPop = (shape) => {
        console.log(shape)
        const [width, height] = [shape[0].length, shape.length]
        for (let c = 0; c + width - 1 < SIZE; c++) {
            let answerTemp = 0
            //같은 column에서 가능하면 내려가서 확인
            for (let r = 0; r + height - 1 < SIZE; r++) {
                let possible = true
                for (let w = 0; w < width; w++) {
                    for (let h = 0; h < height; h++) {
                        if (board[r + h][c + w] == 1 && shape[h][w] == 1) {
                            possible = false
                            break
                        }
                    }
                    if (!possible)
                        break
                }
                if (!possible)
                    break
                answerTemp = isPop(r, height, shape)
                // console.log(123,r,c,answerTemp)
            }
            answer = Math.max(answer, answerTemp)
        }
    }
    const dictShape = { 0: [[1], [1], [1]], 1: [1, 1, 1], 2: [[1, 0], [1, 1]], 3: [[0, 1], [1, 1]], 4: [[1, 1], [0, 1]], 5: [[1, 1], [1, 0]] }
    checkPop(dictShape[block])
    return answer;
}
console.log(solution(0, [[1, 0, 0, 0], [1, 0, 0, 1], [1, 1, 0, 1], [1, 1, 0, 1]]))