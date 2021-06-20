function permutation(arr, selectNum) {
    let result = [];
    if (selectNum === 1) return arr.map((v) => [v]);

    arr.forEach((v, idx, arr) => {
        const fixer = v;
        const restArr = arr.filter((_, index) => index !== idx);
        const permuationArr = permutation(restArr, selectNum - 1);
        const combineFixer = permuationArr.map((v) => [fixer, ...v]);
        result.push(...combineFixer);
    });
    return result;
}
function isPrime(num) {
    if (num <= 1)
        return false
    if (num == 2 || num == 3)
        return true
    for (let i = 2; i < parseInt(Math.sqrt(num)) + 1; i++) {
        if (num % i == 0)
            return false
    }
    return true
}

function solution(numbers) {
    let candidate = new Set();
    for (let i = 0; i <= numbers.length; i++) {
        const perList = permutation([...numbers], i)
        for (let j = 0; j < perList.length; j++) {
            candidate.add(perList[j].join("") * 1)
        }
    }
    let answer = 0
    candidate = [...candidate]
    for (let i = 0; i < candidate.length; i++) {
        if (isPrime(candidate[i]))
            answer += 1
    }

    return answer;
}