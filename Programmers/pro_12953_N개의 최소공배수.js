const gcd = (a, b) => {
    for (let r = 0; b; r = a % b, a = b, b = r);
    return a
}

function solution(arr) {
    return Array(arr.length - 1).fill(0).reduce((acc, _, i) => {
        const [a, b] = [acc, arr[i + 1]]
        return acc = a / gcd(a, b) * b
    }, arr[0])
}