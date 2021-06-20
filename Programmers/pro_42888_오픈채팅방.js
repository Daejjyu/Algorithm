function solution(record) {
    const len = record.length
    const name_dict = []
    for (let i = 0; i < len; i++) {
        if (record[i][0] !== "L") {
            let [_, id, name] = record[i].split(" ")
            name_dict[id] = name
        }
    }
    let answer = [];
    for (let i = 0; i < len; i++) {
        let firstChar = record[i][0]
        if (firstChar !== "C") {
            let [_, id, name] = record[i].split(" ")
            if (firstChar === "E") {
                answer.push(name_dict[id] + "님이 들어왔습니다.")
            } else if (firstChar === "L") {
                answer.push(name_dict[id] + "님이 나갔습니다.")
            }
        }
    }
    return answer;
}