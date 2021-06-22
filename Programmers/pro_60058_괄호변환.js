function solution(p) {
    if (p == '')
        return ''

    const isBalanced = (w) => {
        let [i, check] = [0, 0]
        for (; i < w.length; i++) {
            w[i] == '(' ? check += 1 : check -= 1
            if (check === 0)
                break
        }
        return [w.slice(0, i + 1), w.slice(i + 1, w.length)]
    }

    const isRight = (w) => {
        let check = 0
        for (let i = 0; i < w.length; i++) {
            w[i] == '(' ? check += 1 : check -= 1
            if (check < 0)
                return false
        }
        return check.length ? false : true
    }

    let answer = '';

    const getRight = (w) => {
        if (w == "")
            return ""
        let [u, v] = isBalanced(w)
        if (isRight(u))
            return u + getRight(v)
        let temp = "("
        temp += getRight(v) + ")"
        temp += [...u.slice(1, -1)].map((v) => v == "(" ? ")" : "(").join("")
        return temp
    }
    return getRight(p);
}