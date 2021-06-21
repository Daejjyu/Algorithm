function solution(s) {
    s = s.split(" ").map((v) => parseInt(v)).sort((a, b) => a - b)
    return s[0] + " " + s[s.length - 1];
}