function solution(stones, k) {
    const MAX = 200000000
    const L = stones.length
    let [lo, hi] = [-1, MAX]
    while (lo + 1 < hi) {
        const mid = parseInt((lo + hi) / 2)
        let flag = true
        let cnt = 0
        for (let i = 0; i < L; i++) {
            if (stones[i] - mid < 0)
                cnt += 1
            else
                cnt = 0
            if (cnt >= k) {
                flag = false
                break
            }
        }
        if (flag)
            lo = mid
        else
            hi = mid
    }
    return lo;
}