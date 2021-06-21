function solution(n) {
    let [a, b] = [0, 1]
    for (let i = 0; i < n - 1; i++)
        [a, b] = [b, parseInt(a + b) % 1234567]
    return b;
}