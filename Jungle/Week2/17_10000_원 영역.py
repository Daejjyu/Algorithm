import sys
N = int(sys.stdin.readline())

circle = []
stack = []

for i in range(N):
    x,r = map(int,sys.stdin.readline().split())
    circle.append([x-r,-1]) # 원 시작
    circle.append([x + r, 1]) # 원 끝

circle.sort(key=lambda x:(x[0],-x[1])) #정렬

ans=1
last_pos = 0
# print(circle)
for i in range(len(circle)):
    # print(stack)
    # print(ans)
    new_pos = circle[i][0]
    type = circle[i][1]
    if not stack:
        stack.append([new_pos,0]) # 스위핑 stack 0:생성 1:연결중 -1:끊김
        last_pos = new_pos
    elif (type==-1): # stack push
        if(last_pos == new_pos):
            top = stack[-1]
            stack.pop()
            if(top[1]!=-1): #재갱신 방지
                top[1]=1
            stack.append(top)
            stack.append([new_pos,0])
        else: # 접점이 중간에 끊김 핵심코드
            top = stack[-1]
            stack.pop()
            top[1] = -1  # 끊겼다면
            stack.append(top)
            stack.append([new_pos, 0])
            last_pos = new_pos
    elif(type==1): # stack pop
        top = stack[-1]
        stack.pop()
        if(new_pos == last_pos and top[1]==1):
            ans+=2
        else:
            ans+=1
        last_pos = new_pos
print(ans)
