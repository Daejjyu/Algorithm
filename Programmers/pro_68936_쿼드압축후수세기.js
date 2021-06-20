function solution(arr) {
    const cnt = [0, 0]
    const quad = (r, c, n) => {
        let flag = 1
        let pivot = arr[r][c]
        for (let i = r; i < r + n; i++) {
            for (let j = c; j < c + n; j++) {
                if (arr[i][j] != pivot) {
                    flag = 0
                    break
                }
            }
            if (flag === 0)
                break
        }
        if (flag) {
            cnt[pivot] += 1
            return
        }
        let half = parseInt(n / 2)
        quad(r, c, half)
        quad(r + half, c, half)
        quad(r, c + half, half)
        quad(r + half, c + half, half)
    }
    quad(0, 0, arr.length)
    return cnt;
}