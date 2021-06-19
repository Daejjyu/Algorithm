function solution(dartResult) {
    const score = { "S": 1, "D": 2, "T": 3 }
    let cur = ''
    const stack = []

    for (let i = 0, len = dartResult.length; i < len; i++) {
        let char = dartResult[i]
        let lenS = stack.length
        if ('A' <= char) {
            stack.push(Math.pow(cur, score[char]))
            cur = ''
        } else if (char === '*') {
            if (lenS >= 2)
                stack[lenS - 2] *= 2
            if (lenS)
                stack[lenS - 1] *= 2
        } else if (char === '#' && lenS) {
            stack[lenS - 1] *= -1
        } else {
            cur += char
        }
    }
    return stack.reduce((acc, v) => acc + v);
}