function solution(numbers) {
    let answer = [];
    const len = numbers.length
    for (let i = 0; i < len; i++) {
        for (let j = i + 1; j < len; j++) {
            answer.push(numbers[i] + numbers[j])
        }
    }
    return [...new Set(answer)].sort((a, b) => a - b);
}