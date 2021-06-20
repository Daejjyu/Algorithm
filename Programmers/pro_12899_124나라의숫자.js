function solution(n) {
    if (n <= 3)
        return '124'[n - 1]
    else
        return solution(parseInt((n - 1) / 3)) + '124'[parseInt((n - 1) % 3)]
}