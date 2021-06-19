function solution(answers) {
    const method = [[1, 2, 3, 4, 5]
        , [2, 1, 2, 3, 2, 4, 2, 5]
        , [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    ]

    const cnt = [0, 0, 0]
    for (let i = 0; i < 3; i++) {
        cnt[i] = answers.filter((v, idx) => v === method[i][idx % method[i].length]).length
    }
    const maxN = Math.max(...cnt)

    const answer = []
    for (let i = 0; i < 3; i++) {
        if (cnt[i] == maxN) answer.push(i + 1)
    }
    return answer
}