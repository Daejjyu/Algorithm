function solution(n, a, b) {
    [a, b] = [parseInt((a - 1) / 2), parseInt((b - 1) / 2)]
    let answer = 1;
    while (a != b) {
        answer += 1
        a = parseInt(a / 2)
        b = parseInt(b / 2)
    }
    return answer;
}