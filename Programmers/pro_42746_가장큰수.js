function solution(numbers) {
    let ret = numbers.sort((a, b) => (b + "").repeat(3) > (a + "").repeat(3) ? 1 : -1).join("")
    return ret[0] === "0" ? "0" : ret
}