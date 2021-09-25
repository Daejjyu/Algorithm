# https://velog.io/@ansrjsdn/프로그래머스-level3-줄-서는-방법-Python
import math
def solution(n, k):
    answer = []
    numberList = [i for i in range(1, n+1)]
    while (n != 0):
        temp = math.factorial(n-1)
        index = k // temp
        k = k % temp
        if k == 0:
            answer.append(numberList.pop(index-1))
        else :
             answer.append(numberList.pop(index))
        n -= 1    
    return answer