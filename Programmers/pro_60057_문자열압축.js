function solution(s) {
    const len = s.length
    var answer = len;
    for (let i = 1; i < len / 2 + 1; i++) {
        let str = ''
        let [idx, cnt] = [0, 0]
        while (idx <= len) {
            let cur = s.slice(idx, idx + i)
            if (cur == s.slice(idx + i, idx + 2 * i)) {
                cnt += 1
            } else {
                if (cnt > 0) {
                    str += (cnt + 1) + ""
                    cnt = 0
                }
                str += cur
            }
            idx += i
        }
        answer = Math.min(str.length, answer)
    }
    return answer;
}