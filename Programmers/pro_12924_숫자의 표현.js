function solution(n) {
    let [lo, hi] = [1, 1]
    let sum = 0
    var answer = 0;
    while (lo < n) {
        if (sum > n) {
            sum -= lo
            lo += 1
        } else {
            sum += hi
            hi += 1
        }
        if (sum == n)
            answer += 1
    }
    return answer;
}