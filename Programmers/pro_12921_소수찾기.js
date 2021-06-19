function solution(n) {
    let answer = 0
    const isPrime = [0, 0, ...Array(n).fill(1)];

    for (let i = 2; i < n + 1; i++) {
        if (isPrime[i] == 1) {
            let j = 2
            while (i * j < n + 1)
                isPrime[i * j++] = 0
        }
    }

    for (let i = 2; i < n + 1; i++) {
        answer += isPrime[i]
    }
    return answer;
}