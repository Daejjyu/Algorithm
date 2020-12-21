from collections import deque
N, K  = map(int,input().split())
num = list(str(input()))

que = deque()

for i in num:
    while(K and que and que[-1]<i):
        que.pop()
        K-=1
    que.append(i)

for i in range(len(que)-K):
    print(que[i],end='')