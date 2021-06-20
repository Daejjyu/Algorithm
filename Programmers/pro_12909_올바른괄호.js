function solution(s) {
    let stack = []
    for (let i = 0; i < s.length; i++) {
        let len = stack.length
        let char = s[i]
        if (char == "(")
            stack.push(char)
        else if (len && stack[len - 1] == "(")
            stack.pop()
        else
            return false
    }
    return stack.length ? false : true
}