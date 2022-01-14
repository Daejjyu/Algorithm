const getCntOne = (num) => [...num.toString(2)].filter(v => v === '1').length

function solution(n) {
    const cntOne = getCntOne(n)
    for (let i = n + 1, MAX = 1e6; i < MAX; i++) {
        if (getCntOne(i) === cntOne) return i
    }
}