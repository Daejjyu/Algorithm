function solution(people, limit) {
    people.sort((a, b) => a - b)
    let cnt = 0;
    while (people.length) {
        let last = people.pop()
        if (people[0] + last <= limit)
            people.shift()
        cnt += 1
    }
    return cnt;
}