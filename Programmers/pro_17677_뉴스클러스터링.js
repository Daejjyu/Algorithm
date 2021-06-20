function solution(str1, str2) {
    const getArr = (str) => {
        let [dict_arr, cnt] = [[], 0]
        str = str.toLowerCase()
        for (let i = 1, len = str.length; i < len; i++) {
            if ('a' <= str[i - 1] && str[i - 1] <= 'z' && 'a' <= str[i] && str[i] <= 'z') {
                let word = str[i - 1] + str[i]
                dict_arr[word] ? dict_arr[word] += 1 : dict_arr[word] = 1
                cnt += 1
            }
        }
        return [dict_arr, cnt]
    }

    const [[dict_arr1, len1], [dict_arr2, len2]] = [getArr(str1), getArr(str2)]
    let intersect = 0
    for (let i in dict_arr1) {
        let minN = Math.min(dict_arr1[i], dict_arr2[i])
        if (minN > 0) {
            intersect += minN
        }
    }
    var answer = (len1 + len2) - intersect;
    return answer ? parseInt((intersect / answer) * 65536) : 65536;
}