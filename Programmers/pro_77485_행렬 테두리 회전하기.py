def solution(rows, columns, queries):
    answer=[]
    arr = [[(columns*r+c+1) for c in range(columns)] for r in range(rows)]
    for r1,c1,r2,c2 in queries:
        minArr = []
        #top
        temp1 = arr[r1-1][c2-1]
        minArr.append(temp1)
        for i in range(c2-1,c1-1,-1):
            arr[r1-1][i]=arr[r1-1][i-1]
            minArr.append(arr[r1-1][i-1])
        #right
        temp2 = arr[r2-1][c2-1]
        minArr.append(temp2)
        for i in range(r2-1,r1-1,-1):
            arr[i][c2-1]=arr[i-1][c2-1]
            minArr.append(arr[i-1][c2-1])
        arr[r1][c2-1]=temp1
        #bottom
        temp1 = arr[r2-1][c1-1]
        minArr.append(temp1)
        for i in range(c1,c2):
            arr[r2-1][i-1]=arr[r2-1][i]
            minArr.append(arr[r2-1][i])
        arr[r2-1][c2-2]=temp2
        # #left
        for i in range(r1,r2):
            arr[i-1][c1-1]=arr[i][c1-1]
            minArr.append(arr[i][c1-1])
        arr[r2-2][c1-1]=temp1
        answer.append(min(minArr))
        
    return answer