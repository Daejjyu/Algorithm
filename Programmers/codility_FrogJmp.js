// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(X, Y, D) {
    if (Y <= X)
        return 0
    return Math.ceil((Y - X) / D)
}