function solution(A) {
    // write your code in JavaScript (Node.js 8.9.4)
    const MAX = 1000000000
    let [zeroCnt,ans] =[0,0]
    for(let i=0; i<A.length; i++){
        let cur = A[i]
        if(cur==0){
            zeroCnt+=1            
        }else{
            ans+=zeroCnt
        }
        if(ans>MAX)
            return -1
    }
    return ans
}