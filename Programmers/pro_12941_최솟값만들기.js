const cmp = (a, b) => a - b
function solution(A, B) {
    return B.sort(cmp).reverse() && A.sort(cmp).reduce((a, _, i) => a += A[i] * B[i], 0);
}