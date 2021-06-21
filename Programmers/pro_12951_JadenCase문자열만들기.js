function solution(s) {
    s = [...s.toLowerCase()]
    s[0] = s[0].toUpperCase()
    for (let i = 1; i < s.length; i++) {
        if (s[i - 1] === ' ')
            s[i] = s[i].toUpperCase()
    }
    return s.join("");
}