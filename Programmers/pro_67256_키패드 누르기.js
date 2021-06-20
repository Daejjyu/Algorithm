function solution(numbers, hand) {
    const getDist = (a, b) => {
        [a, b] = [a - 1, b - 1]
        let [r1, c1] = [parseInt(a / 3), parseInt(a % 3)]
        let [r2, c2] = [parseInt(b / 3), parseInt(b % 3)]
        return Math.abs(c2 - c1) + Math.abs(r2 - r1)
    }
    var answer = '';
    let [left, right] = [10, 12]
    for (let i = 0, len = numbers.length; i < len; i++) {
        let targetNum = numbers[i]
        if (targetNum === 0) targetNum = 11
        if (targetNum % 3 === 1) {
            answer += "L"
            left = targetNum
        } else if (targetNum % 3 === 0) {
            answer += "R"
            right = targetNum
        } else {
            let [leftDist, rightDist] = [getDist(left, targetNum), getDist(right, targetNum)]
            if (hand === "left" && leftDist === rightDist || leftDist < rightDist) {
                answer += "L"
                left = targetNum
            } else {
                answer += "R"
                right = targetNum
            }
        }
    }
    return answer;
}