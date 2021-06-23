// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(A, B, K) {
    if (A == B && A % K == 0)
        return 1
    let [s, e] = [parseInt(A / K), parseInt(B / K)]
    let answer = 0
    if (A % K == 0)
        answer += 1
    answer += e - s
    return answer
}