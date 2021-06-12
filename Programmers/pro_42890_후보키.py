def solution(relation):
    transpose = [x for x in zip(*relation)]
    colLen =len(transpose[0])
    isKey = [0]*colLen
    for i in range(len(transpose)):
        print(transpose[i])
        if(len(transpose[i])==len(set(transpose[i]))):
            isKey[i]=1
    print(isKey)
    return colLen