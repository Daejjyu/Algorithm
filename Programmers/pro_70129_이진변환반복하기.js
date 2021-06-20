function solution(s) {
    let [cnt, zeroCnt] = [0, 0]
    while (s != "1") {
        cnt += 1
        let s2 = s.replace(/0/g, '')
        zeroCnt += s.length - s2.length
        s = s2.length.toString(2)
    }
    return [cnt, zeroCnt];
}