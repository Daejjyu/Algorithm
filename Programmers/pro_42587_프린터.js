function solution(priorities, location) {
    var answer = 0;
    const prio = priorities.map((v, i) => [v, i])
    while (prio.length) {
        let [top, idx] = prio.shift()
        let flag = 0
        for (let i = 0; i < prio.length; i++) {
            if (top < prio[i][0]) {
                flag = 1
                break
            }
        }
        if (flag) {
            prio.push([top, idx])
        } else {
            answer += 1
            if (idx == location)
                return answer
        }
    }
    return -1;
}