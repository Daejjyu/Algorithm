function solution(arr) {
    const gcd = (a, b) => {
        for (let r = 0; b; r = parseInt(a % b), a = b, b = r) {
        };
        return a
    }

    for (let i = 1; i < arr.length; i++) {
        let [a, b] = [arr[i - 1], arr[i]]
        arr[i] = parseInt(a * b / gcd(a, b))
    }
    console.log(arr)
    return arr[arr.length - 1];
}