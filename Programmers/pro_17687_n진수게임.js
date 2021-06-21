function solution(n, t, m, p) {
    var answer = '';
    let idx = 0
    for (let i = 0; ; i++) {
        let str = i.toString(n).toUpperCase()
        for (let j = 0; j < str.length; j++) {
            if (parseInt(idx % m) === (p - 1))
                answer += str[j]
            idx += 1
        }
        if (answer.length >= t)
            break
    }
    return answer.slice(0, t);
}