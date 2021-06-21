function solution(arr1, arr2) {
    const [R, C, K] = [arr1.length, arr2[0].length, arr1[0].length]
    var answer = Array.from(Array(R), () => Array.from(Array(C), () => 0))
    for (let r = 0; r < R; r++) {
        for (let c = 0; c < C; c++) {
            for (let k = 0; k < K; k++) {
                answer[r][c] += arr1[r][k] * arr2[k][c]
            }
        }
    }
    return answer;
}