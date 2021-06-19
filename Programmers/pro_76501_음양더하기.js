function solution(absolutes, signs) {
    let answer = absolutes.reduce((acc, v, i) => {
        return signs[i] ? acc + v : acc - v
    }, 0)
    return answer;
}