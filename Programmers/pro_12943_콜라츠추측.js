function solution(num) {
    let cnt = 0
    while (num > 1 && cnt < 500) {
        cnt += 1
        if (num % 2)
            num = num * 3 + 1
        else
            num /= 2
    }
    return cnt < 500 ? cnt : -1;
}