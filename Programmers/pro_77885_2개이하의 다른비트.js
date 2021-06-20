
function solution(numbers) {
    //마지막 0을 찾고 01 ->10    0 ->1
    var answer = [];
    for (let i = 0; i < numbers.length; i++) {
        let bin = [..."0" + numbers[i].toString(2)]
        let idx = bin.lastIndexOf("0")
        bin[idx] = "1"
        if (idx + 1 < bin.length)
            bin[idx + 1] = "0"
        answer.push(parseInt((bin.join("")), 2))
    }
    return answer;
}