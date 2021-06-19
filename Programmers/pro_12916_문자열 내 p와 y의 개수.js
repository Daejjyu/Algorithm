function solution(s) {
    s = s.toLowerCase()
    let cnt = 0
    for (let i = 0; i < s.length; i++)
        if (s[i] == 'p') {
            cnt += 1
        } else if (s[i] == 'y') {
            cnt -= 1
        }

    return cnt ? false : true;
}