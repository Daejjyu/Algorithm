function solution(arr1, arr2) {
    return arr1.map((r, i) => r.map((c, j) => c + arr2[i][j]));
}