function solution(n, m) {
    const gcd = ((a, b) => {
        let r = 0
        r = parseInt(a % b)
        while (b) {
            r = parseInt(a % b)
            a = b
            b = r
        }
        return a
    })(n, m)
    return [gcd, n * m / gcd];
}