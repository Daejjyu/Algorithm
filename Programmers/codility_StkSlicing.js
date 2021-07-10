function solution(A) {
    const sliceIdxList = []
    const [MAX, MIN] = [1000000000, 0]
    let [prevMin, prevMax] = [MAX + 1, MIN - 1]

    for (let i = 0, len = A.length; i < len; i++) {
        let cur = A[i]
        if (cur > prevMax) {
            prevMax = cur
            sliceIdxList.push([i, prevMin])
        }
        if (cur < prevMin) {
            while (sliceIdxList.length > 0) {
                let L = sliceIdxList.length
                if (cur < sliceIdxList[L - 1][1]) {
                    sliceIdxList.pop()
                }
            }
            prevMin = cur
        }
        console.log(i, cur, sliceIdxList)
    }
    return sliceIdxList.length + 1
}
console.log(solution([2, 3, 4, 1, 6, 5, 9, 7]))
