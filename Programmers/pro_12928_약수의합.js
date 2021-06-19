function solution(n) {
    let answer = 0;
    for (let i = 1; i < parseInt(n / 2) + 1; i++)
        if (n % i == 0)
            answer += i
    return n + answer;
}
