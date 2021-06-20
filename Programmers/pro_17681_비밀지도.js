function solution(n, arr1, arr2) {
    return arr1.map((v, i) => (" ".repeat(n) + (v | arr2[i]).toString(2).replace(/1/g, "#").replace(/0/g, " ")).slice(-n));
}