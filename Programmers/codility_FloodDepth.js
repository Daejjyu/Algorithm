function solution(A) {
    // write your code in JavaScript (Node.js 8.9.4)
    const range = []
    const getRange = (s, e, dir) => {
        let height = 0
        for (let i = s; i != e; i += dir) {
            if (A[i] >= height) {
                range.push(i)
                height = A[i]
            }
        }
    }
    const len = A.length
    getRange(0, len, 1)
    getRange(len - 1, -1, -1)
    range.sort((a, b) => a - b)

    let answer = 0
    for (let i = 1; i < range.length; i++) {
        let [prev, cur] = [range[i - 1], range[i]]
        let height = Math.min(A[prev], A[cur])
        for (let j = prev + 1; j < cur; j++) {
            answer = Math.max(answer, height - A[j])
        }
    }
    return answer
}