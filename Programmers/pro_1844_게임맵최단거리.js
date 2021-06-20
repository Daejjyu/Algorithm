function solution(maps) {
    const [R, C] = [maps.length, maps[0].length]
    const visited = Array.from(Array(R), () => Array.from(Array(C), () => 0))
    const que = [[0, 0]]
    const move = [[1, 0], [0, 1], [-1, 0], [0, -1]]

    let answer = 1;
    let loop = 0
    while (que.length) {
        loop += 1
        let len = que.length
        while (len--) {
            let [top_r, top_c] = que.shift()
            for (let i = 0; i < 4; i++) {
                let [dr, dc] = move[i]
                let [nextR, nextC] = [top_r + dr, top_c + dc]
                if (nextR < 0 || R <= nextR || nextC < 0 || C <= nextC)
                    continue
                if (maps[nextR][nextC] == 1 && visited[nextR][nextC] == 0) {
                    if (nextR == R - 1 && nextC == C - 1)
                        return answer + 1
                    visited[nextR][nextC] = 1
                    que.push([nextR, nextC])
                }
            }
        }
        answer += 1
    }
    return -1;
}