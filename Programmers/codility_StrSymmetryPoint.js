// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(S) {
    // write your code in JavaScript (Node.js 8.9.4)
    const len = S.length
    if (len === 0 || len % 2 === 0)
        return -1
    const center = parseInt(S.length / 2)
    let left = S.slice(0, center)
    let right = S.slice(center + 1, len)
    return (left === [...right].reverse().join("")) ? left.length : -1
}