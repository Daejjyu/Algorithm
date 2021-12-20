function solution(n, arr1, arr2) {
    return arr1.map((_, i) => (arr1[i] | arr2[i]).toString(2).replace(/1/g, '#').replace(/0/g, ' ').padStart(n, ' '));
}