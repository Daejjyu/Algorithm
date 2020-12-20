from collections import deque
size= int(input())
board = [[0 for r in range(size)] for c in range(size)]
#apple 1 snake 2
T = int(input())
for i in range(T):
    r, c = map(int,input().split())
    board[r-1][c-1]=1
board[0][0] =2
snake = deque()
snake.append([0,0])

dr = [[0,1],[1,0],[0,-1],[-1,0]]
cur_dr = 0
time = 0
T = int(input())
flag=True
C = 'init'
for i in range(T+1):
    if(flag==False):
        break
    if(i<T):
        X, C = input().split()
    elif(i==T):
        X = 10000
    X = int(X)

    while(time<X):
        # for i in range(size):
        #     print(board[i])
        # print()
        time+=1
        snake.appendleft([snake[0][0]+dr[cur_dr][0], snake[0][1]+dr[cur_dr][1]])
        nextR=snake[0][0]
        nextC=snake[0][1]
        if(nextR<0 or nextC <0 or nextR>=size or nextC >=size): #범위 벗어남
            flag=False
            break
        if(board[nextR][nextC]==2): # 몸통일경우
            flag = False
            break
        if(board[nextR][nextC]==1): # 사과면
            board[nextR][nextC] = 2
            continue
        else:
            board[nextR][nextC] = 2
            board[snake[-1][0]][snake[-1][1]] = 0
            snake.pop()

    if(C == 'D'):
        cur_dr = (cur_dr+1)%4
    elif(C=='L'):
        cur_dr -= 1
        if(cur_dr<0): cur_dr = 3


print(time)
