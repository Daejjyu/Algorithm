def solution(numbers):
    # 제일 뒤쪽 0에서 {01->10} 뒤에 1 없으면 {0->1}로
    # 모두 다 1이면 앞에 10으로 바꾸기
    # 0일 때 예외 처리
    answer = []
    for i in numbers:
        if(i==0):
            answer.append(1)
            continue
        cur = list(bin(i)[2:])
        flag=True
        for i in range(len(cur)-1,0,-1):
            if(cur[i]=='0'):
                if(i+1<len(cur) and cur[i+1]=='1'):
                    cur[i],cur[i+1]='1','0'
                else:
                    cur[i]='1'
                flag=False
                answer.append(int(''.join(cur),2))
                break
        if(flag):
            answer.append(int("10"+''.join(cur[1:]),2))
    return answer
