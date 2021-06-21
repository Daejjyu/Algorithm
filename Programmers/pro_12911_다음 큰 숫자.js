function solution(n) {
    const len = n.toString(2).replace(/0/g, "").length
    while (n++) {
        if (n.toString(2).replace(/0/g, "").length === len)
            return n
    }
}