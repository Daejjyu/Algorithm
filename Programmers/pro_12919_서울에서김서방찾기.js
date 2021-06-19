function solution(seoul) {
    for (let i = 0, len = seoul.length; i < len; i++)
        if (seoul[i] === 'Kim')
            return "김서방은 " + i + "에 있다"
    return -1;
}