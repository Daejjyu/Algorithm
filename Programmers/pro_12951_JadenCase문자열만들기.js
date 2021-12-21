function solution(s) {
    return s.split(' ').map(v => v ? v[0].toUpperCase() + v.substring(1).toLowerCase() : '').join(' ')
}