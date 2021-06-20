function solution(s) {
    const stack = []
    for (let i = 0, lenS = s.length; i < lenS; i++) {
        let lenStack = stack.length
        if (lenStack && stack[lenStack - 1] == s[i]) {
            stack.pop()
        } else {
            stack.push(s[i])
        }
    }
    return stack.length ? 0 : 1
}