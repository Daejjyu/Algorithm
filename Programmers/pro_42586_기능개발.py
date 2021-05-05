def solution(progresses, speeds):
    answer = []
    day = 0
    count = 0
    while len(progresses)> 0:
        if (progresses[0] + day*speeds[0]) >= 100:
            progresses.pop(0) # list는 뒤의 것을 제거 시 O(1), 0번째 것을 제거하는데에는 O(n) , 모두 다 옮겨야 하기 떄문
            speeds.pop(0) # 따라서 비효율적인 코드다. cur_idx 를 관리하면서 빠르게 하는 것이 좋을 듯
            count += 1
        else:
            if count > 0:
                answer.append(count)
                count = 0
            day += 1
    answer.append(count)
    return answer