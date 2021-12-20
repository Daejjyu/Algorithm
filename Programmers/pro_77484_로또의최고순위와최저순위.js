function solution(lottos, win_nums) {
    const rank = [6, 6, 5, 4, 3, 2, 1]

    let zeroCnt = lottos.filter((v) => !v).length
    let minCnt = lottos.filter((v) => win_nums.includes(v)).length

    let maxCnt = minCnt + zeroCnt

    return [rank[maxCnt], rank[zeroCnt]];
}