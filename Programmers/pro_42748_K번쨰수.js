function solution(array, commands) {
    const answer = commands.map(cmd => {
        let [s, e, k] = cmd
        const sliced_arr = array
            .slice(s - 1, e)
            .sort((a, b) => a - b)
        return sliced_arr[k - 1]
    })
    return answer;
}