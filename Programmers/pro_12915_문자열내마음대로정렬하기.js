function solution(strings, n) {
    return strings.sort((a, b) => b = a[n] == b[n] ? (a < b ? -1 : 1) : (a[n] < b[n] ? -1 : 1));
}