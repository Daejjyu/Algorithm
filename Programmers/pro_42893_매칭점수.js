function solution(word, pages) {
    word = word.toLowerCase()
    const dictLink = []
    const pageReg = /(?<=https:\/\/)\S+"/
    const linkReg = /(?<=<a href="https:\/\/)\S+"/gi
    const bodyReg = /<\S+>/g
    const [scoreBase, scoreForLinked] = [[], []]
    const pageArr = []
    for (let i = 0; i < pages.length; i++) {
        let [_, head, body] = pages[i].split("head>")
        let page = head.match(pageReg)[0]
        pageArr.push(page)
        let link = body.match(linkReg)
        link = link ? link : []
        let innerText = body.replace(bodyReg, '').toLowerCase().replace(/\n/g, "").split(/[^a-zA-Z]/)
        for (let i = 0; i < link.length; i++) {
            let cur = link[i]
            dictLink[cur] ? dictLink[cur].push(page) : dictLink[cur] = [page]
        }

        scoreBase[page] = innerText ? innerText.filter((v) => word == v).length : 0
        scoreForLinked[page] = link && link.length ? scoreBase[page] / link.length : 0
    }
    let answer = 0
    let [maxScore, idx] = [0, 0]
    for (let i = 0; i < pageArr.length; i++) {
        let page = pageArr[i]
        let score = scoreBase[page]
        let arr = dictLink[page] ? dictLink[page] : []
        for (let i = 0; i < arr.length; i++) {
            let cur = arr[i]
            score += scoreForLinked[cur]
        }
        if (maxScore < score) {
            maxScore = score
            answer = i
        }
        idx++
    }
    return answer;
}