function solution(n) {
    let [lo, hi] = [1, 1]
    let answer = 0;
    let sum = 0
    while (1) {
        if (sum >= n) sum -= lo++;
        else if (hi === n + 1) break;
        else sum += hi++;
        if (sum === n) answer++;
    }
    return answer;
}