
function combination(arr, selectNum) {
    const result = [];
    if (selectNum === 1) return arr.map((v) => [v]);
    arr.forEach((v, idx, arr) => {
        const fixed = v;
        const restArr = arr.slice(idx + 1);
        const combinationArr = combination(restArr, selectNum - 1);
        const combineFix = combinationArr.map((v) => [fixed, ...v]);
        result.push(...combineFix);
    });
    return result;
}

function bisect(arr, num) {
    let [lo, hi] = [-1, arr.length]
    while (lo + 1 < hi) {
        let mid = parseInt((lo + hi) / 2)
        if (arr[mid] >= num)
            hi = mid
        else
            lo = mid
    }
    return arr.length - hi
}

function solution(info, query) {
    let dict_info = []
    for (let i = 0; i < info.length; i++) {
        let line = info[i].split(" ")
        let [option, num] = [line.slice(0, -1), line.slice(-1) * 1]
        for (let j = 1; j < line.length; j++) {
            let comb = combination(option, j)
            for (let k = 0; k < comb.length; k++) {
                let str = "-" + comb[k].join("")
                dict_info[str] ? dict_info[str].push(num) : dict_info[str] = [num]
            }
        }
        dict_info["-"] ? dict_info["-"].push(num) : dict_info["-"] = [num]
    }

    for (let i in dict_info) {
        dict_info[i].sort((a, b) => a - b)
    }

    let answer = [];
    for (let i = 0; i < query.length; i++) {
        let line = query[i].replace(/-|(and )/g, "").split(" ")
        let [option, num] = [line.slice(0, -1), line.slice(-1) * 1]
        let str = "-" + option.join("")
        let arr = dict_info[str]
        arr ? answer.push(bisect(arr, num)) : answer.push(0)
    }
    return answer;
}
