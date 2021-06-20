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

function solution(orders, course) {
    const course_dict = []
    const max_dict = []
    for (let i = 0; i < orders.length; i++) {
        let order = [...orders[i]].sort()
        for (let j = 1; j <= order.length; j++) {
            if (course.indexOf(j) != -1) {
                let comb = combination(order, j)
                for (let k = 0; k < comb.length; k++) {
                    let elem = comb[k].join("")
                    course_dict[elem] ? course_dict[elem] += 1 : course_dict[elem] = 1
                    max_dict[j] ? max_dict[j] = Math.max(course_dict[elem], max_dict[j]) : max_dict[j] = course_dict[elem]
                }
            }

        }
    }
    let answer = [];
    for (let i in course_dict) {
        let cnt = course_dict[i]
        if (cnt >= 2 && cnt == max_dict[i.length])
            answer.push(i)
    }
    return answer.sort();
}