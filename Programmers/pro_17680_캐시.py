function solution(cacheSize, cities) {
    const cache =[]    
    var answer = 0;
    
    for(let i=0; i<cities.length; i++){
        const lenCache = Math.min(cache.length,cacheSize)
        let flag = 0
        let city = cities[i].toLowerCase()
        let [max_cnt,max_idx] = [-1,-1]
        for(let j=0; j<lenCache; j++){
            cache[j][1]+=1
            let [name,cnt] = cache[j]
            if(name==city){
                flag=1
                answer+=1
                cache[j][1]=0
            }
            if(max_cnt<=cnt)
                [max_cnt,max_idx]=[cnt,j]
        }
        if(flag==0){
            answer+=5
            if(cache.length<cacheSize)
                cache.push([city,0])
            else{
                cache[max_idx]=[city,0]
            }
        }
    }
    return answer;
}
console.log(solution(5,["seoul","seoul","seoul"]))
