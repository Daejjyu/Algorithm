function solution(expression) {
    expression = expression.split(/([\*\+-])/g)
    const prio = ["*+-", "*-+", "+*-", "+-*", "-+*", "-*+"]
    let answer = 0;
    for (let i = 0; i < prio.length; i++) {
        let ret = Array.from(expression)
        for (let j = 0; j < 3; j++) {
            let operator = prio[i][j]
            let idx = ret.indexOf(operator)
            while (idx != -1) {
                let elem = 0
                if (operator == "*")
                    elem = ret[idx - 1] * ret[idx + 1]
                else if (operator == "+")
                    elem = ret[idx - 1] * 1 + ret[idx + 1] * 1
                else
                    elem = ret[idx - 1] * 1 - ret[idx + 1] * 1
                ret.splice(idx - 1, 3, elem)
                idx = ret.indexOf(operator)
            }
        }
        answer = Math.max(answer, Math.abs(ret))
    }
    return answer;
}