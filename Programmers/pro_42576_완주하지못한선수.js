function solution(participant, completion) {
    const dict = []
    completion.forEach((v) => {
        dict[v] = dict[v] ? dict[v] + 1 : 1
    })
    for (let i = 0, len = participant.length; i < len; i++) {
        let v = participant[i]
        dict[v] = dict[v] ? dict[v] - 1 : -1
        if (dict[v] == -1)
            return v
    }
    return -1;
}