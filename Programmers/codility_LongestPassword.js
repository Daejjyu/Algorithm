function solution(S) {
    // write your code in JavaScript (Node.js 8.9.4)
    let answer = -1
    const arr = S.split(" ")
    for (let i = 0; i < arr.length; i++) {
        let str = arr[i]
        if (str.length % 2 == 0) //condition 3
            continue
        if (str !== str.replace(/[^a-zA-Z0-9]/g, "")) //condition 1
            continue
        if (str.replace(/[^a-zA-Z]/g, "").length % 2) //condition 2
            continue
        answer = Math.max(answer, str.length)
    }
    return answer
}