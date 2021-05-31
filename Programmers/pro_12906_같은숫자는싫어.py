def solution(arr):
    answer = [arr[0]]
    for i in range(1,len(arr)):
        if(arr[i-1]==arr[i]):
            continue
        answer.append(arr[i])
    return answer