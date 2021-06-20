function solution(s, n) {
    let arr = [...s]
    const last = ['z'.charCodeAt(0), 'Z'.charCodeAt(0)]
    arr = arr.map((v) => {
        let next = v.charCodeAt(0) + n
        if ('a' <= v && v <= 'z') {
            v = next > last[0] ? String.fromCharCode(next - 26) : String.fromCharCode(next)
        } else if ('A' <= v && v <= 'Z') {
            v = next > last[1] ? String.fromCharCode(next - 26) : String.fromCharCode(next)
        }
        return v
    })
    return arr.join('');
}