function solution(word) {
    word = [...word]
    const dictChar = {'A':1,'E':2,'I':3,'O':4,'U':5}
    const dictNum = {'1':'A','2':'E','3':'I','4':'O','5':'U'}
    var answer = 0;
    while(word.length){
        const lastChar = word.splice(word.length-1,1)
        if(lastChar == 'A'){
            answer+=1
        }else{
            const prevChar = dictNum[dictChar[lastChar]-1]
            word.push(prevChar)
            while(word.length<5){
                word.push('U')
            }
            answer += 1
        } 
    }
    return answer;
}

//3 -> 1 + 25555 ->  1+ 5 + 2555 -> 1+ 5+ 25545