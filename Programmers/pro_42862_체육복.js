function solution(n, lost, reserve) {
    let clothes = Array.from({ length: n }, () => 1)
    for (let i in lost) {
        let lostIdx = lost[i] - 1
        clothes[lostIdx] -= 1
    }

    for (let i in reserve) {
        let reserveIdx = reserve[i] - 1
        if (clothes[reserveIdx] == 0) {
            clothes[reserveIdx] = 1
            reserve[i] = -1 // used
        }
    }

    reserve.sort().reverse()
    for (let i in reserve) {
        if (reserve[i] == -1)
            break
        let reserveIdx = reserve[i] - 1
        if (reserveIdx > 0 && clothes[reserveIdx - 1] == 0) {
            clothes[reserveIdx - 1] += 1
        } else if (reserveIdx < n - 1 && clothes[reserveIdx + 1] == 0) {
            clothes[reserveIdx + 1] += 1
        }
    }

    return clothes.filter(v => v == 1).length
}