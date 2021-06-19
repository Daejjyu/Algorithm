function solution(arr) {
    const minN = Math.min(...arr)
    arr = arr.filter((v) => v > minN)
    return arr.length ? arr : [-1];
}