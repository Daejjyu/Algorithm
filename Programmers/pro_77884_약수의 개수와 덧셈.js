function solution(left, right) {
    let answer = 0;
    for (let i = left; i <= right; i++) {
        let sqrtN = Math.sqrt(i, 2)
        if (sqrtN === parseInt(sqrtN))
            answer -= i
        else
            answer += i
    }
    return answer;
}