function solution(arr) {
    return arr.filter((v, i) => arr[i] != arr[i - 1]);
}