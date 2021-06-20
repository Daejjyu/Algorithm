function solution(numbers, target) {
    const len = numbers.length
    const getTarget = (num, cnt) => {
        if (cnt == len)
            return num == target ? 1 : 0
        return getTarget(num - numbers[cnt], cnt + 1) + getTarget(num + numbers[cnt], cnt + 1)
    }
    return getTarget(0, 0);
}