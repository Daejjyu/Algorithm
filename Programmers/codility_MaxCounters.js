// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(N, A) {
    const counter = Array(N+1).fill(0)
    // write your code in JavaScript (Node.js 8.9.4)
    let [maxN, lastMax] = [0,0]
    for (let i=0; i<A.length; i++){
        let cur = A[i]
        if(cur<=N){
            counter[cur] = Math.max(counter[cur],lastMax)
            counter[cur]+=1            
            maxN=Math.max(maxN,counter[cur])
        }else if(cur==(N+1)){
            lastMax=maxN
        }
    }
    for(let i=0; i<counter.length; i++){
        counter[i] = Math.max(counter[i],lastMax)
    }
    return counter.slice(1,N+1)
}