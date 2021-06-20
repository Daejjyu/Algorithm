function solution(n, words) {
    const dict_word = []
    dict_word[words[0]] = 1
    for (let i = 1; i < words.length; i++) {
        let [prev, cur] = [words[i - 1], words[i]]
        let [last, first] = [prev[prev.length - 1], cur[0]]
        if (dict_word[cur] || last != first)
            return [parseInt(i % n) + 1, parseInt(i / n) + 1]
        dict_word[cur] = 1
    }
    return [0, 0];
}