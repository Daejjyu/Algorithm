function solution(clothes) {
    const dict = []
    for (let i = 0; i < clothes.length; i++) {
        let [value, key] = clothes[i]
        dict[key] ? dict[key] += 1 : dict[key] = 1
    }
    var answer = 1;
    for (let i in dict)
        answer *= (dict[i] + 1)
    return answer - 1;
}