def solution(A, B):
    A.sort()
    B.sort()
    j=len(B)-1
    answer = 0
    for i in range(len(A)-1,-1,-1):
        if(A[i]<B[j]):
            answer+=1
            j-=1
    return answer