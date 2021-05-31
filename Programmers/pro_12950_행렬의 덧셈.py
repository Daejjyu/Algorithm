def solution(arr1, arr2):
    answer= [[] for _ in range(len(arr1))]
    loop=0
    for e1, e2 in zip(arr1,arr2):
        for i,j in zip(e1,e2):
            answer[loop].append(i+j)
        loop+=1
    # answer = [[i+j for i,j in zip(e1,e2)] for e1,e2 in zip(arr1,arr2)]
    return answer