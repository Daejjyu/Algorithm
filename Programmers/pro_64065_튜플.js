function solution(s) {
    s = s.replace(/^{{|}}$/g, '')
        .split("},{")
        .map((v) => v.split(",").map((v) => v * 1))
        .sort((a, b) => a.length - b.length)
    let answer = new Set();
    for (let i = 0; i < s.length; i++) {
        let arr = s[i]
        for (let j = 0; j < arr.length; j++) {
            answer.add(arr[j])
        }
    }
    return [...answer];
}