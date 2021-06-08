def fillNum(arr,row,col,level,num):
    for i in range(level):
        arr[row+i][col]=num+i
    for i in range(level):
        arr[row+level-1][col+i]=num+level-1+i
    for i in range(level-1):
        arr[row+level-1-i][col+level-1-i]=num+2*level-2+i
    if(level-3>0):
        fillNum(arr,row+2,col+1,level-3,num+3*level-3)

def solution(n):   
    arr = [[] for _ in range(n)]
    for i in range(n):
        arr[i]=[0]*(i+1)
    fillNum(arr,0,0,n,1)
    answer = []
    for i in arr:
        answer += i
    return answer