function solution(progresses, speeds) {
    var answer = [0];
    const len = progresses.length
    let day = 0
    for (let i = 0; i < len; i++) {
        if (progresses[i] + day * speeds[i] >= 100)
            answer[answer.length - 1] += 1
        else {
            day = Math.ceil((100 - progresses[i]) / speeds[i])
            answer.push(1)
        }
    }
    return answer[0] === 0 ? answer.slice(1) : answer;
}