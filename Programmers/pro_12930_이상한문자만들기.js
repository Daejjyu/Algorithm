function solution(s) {
    const arr = [...s.toLowerCase()]
    let idx = 0
    const answer = arr.map((v) => {
        if (v == ' ')
            idx = -1
        if (idx % 2 === 0)
            v = v.toUpperCase()
        idx += 1
        return v
    })
    return answer.join('');
}