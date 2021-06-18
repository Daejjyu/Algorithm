def solution(routes):
    routes = sorted(routes, key = lambda x:x[0]) # 진입 지점 순으로 정렬
    answer = 1
    a = [routes[0]] # 첫번째 차량은 포함하고 시작
    
    for i in range(1, len(routes)):
        if (routes[i][0] <= a[answer-1][1]): # 공통범위가 존재하면
            a[answer-1] = [routes[i][0], min(a[answer-1][1], routes[i][1])]
        else: # 공통범위가 존재하지 않는다면
            answer += 1
            a.append(routes[i])
    return answer