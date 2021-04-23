# 13분 소요
# s[::-1] string reverse 문법 서핑하였음
def solution(n, arr1, arr2):
    answer = []
    map = []
    for i, j in zip(arr1,arr2):
        bit = i|j
        s = ''
        for _ in range(n):
            if(bit>0 and bit%2):
                s+='#'
            else:
                s+=' '
            bit//=2
        answer.append(s[::-1])
    return answer