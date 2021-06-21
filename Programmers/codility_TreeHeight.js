// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(T) {
    // write your code in JavaScript (Node.js 8.9.4)
    const getHeight = (node, cnt) => {
        if (node === null)
            return cnt - 1
        let ret = cnt
        ret = Math.max(getHeight(node.l, cnt + 1), getHeight(node.r, cnt + 1))
        return ret
    }
    return getHeight(T, 0)
}