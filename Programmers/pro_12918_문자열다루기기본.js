function solution(s) {
    return (s.length === 4 || s.length === 6) && [...s].filter(c => c == +c).length === s.length;
}