function solution(n) {
    let answer = 0;
    while (parseInt(n)) {
        answer += parseInt(n % 10)
        n /= 10
    }
    return parseInt(answer);
}