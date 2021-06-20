function solution(d, budget) {
    d.sort((a, b) => a - b)
    let sum = 0
    let len = d.length
    for (let i = 0; i < len; i++) {
        if (sum + d[i] <= budget) {
            sum += d[i]
        } else
            return i
    }
    return len;
}