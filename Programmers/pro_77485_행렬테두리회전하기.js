function solution(rows, columns, queries) {
    const arr = []
    for (let r = 0; r < rows; r++) {
        arr.push([])
        for (let c = 1; c <= columns; c++) {
            arr[r].push(r * columns + c)
        }
    }
    const rotation = (query) => {
        let [r1, c1, r2, c2] = query
        r1 = r1 - 1, c1 = c1 - 1, r2 = r2 - 1, c2 = c2 - 1
        let temp = [arr[r1][c2], arr[r2][c2], arr[r2][c1], arr[r1][c1]]
        let minN = Math.min(...temp)
        for (let i = c2; i > c1; i--) {
            arr[r1][i] = arr[r1][i - 1]
            minN = Math.min(minN, arr[r1][i])
        }

        for (let i = r2; i > r1; i--) {
            arr[i][c2] = arr[i - 1][c2]
            minN = Math.min(minN, arr[i][c2])
        }
        arr[r1 + 1][c2] = temp[0]

        for (let i = c1; i < c2; i++) {
            arr[r2][i] = arr[r2][i + 1]
            minN = Math.min(minN, arr[r2][i])
        }
        arr[r2][c2 - 1] = temp[1]

        for (let i = r1; i < r2; i++) {
            arr[i][c1] = arr[i + 1][c1]
            minN = Math.min(minN, arr[i][c1])
        }
        arr[r2 - 1][c1] = temp[2]
        return minN
    }

    var answer = [];
    for (let i = 0; i < queries.length; i++) {
        answer.push(rotation(queries[i]))
    }
    return answer;
}