import sys
from collections import deque

N = int(sys.stdin.readline())

que = deque()
for i in range(N):
    command = list(sys.stdin.readline().split())
    if (command[0] == 'push'):
        que.append(int(command[1]))
    if (command[0] == 'pop'):
        if que:
            sys.stdout.write('%d\n'%int(que[0]))
            que.popleft()
        else:
            sys.stdout.write('%d\n'%-1)
    if (command[0] == 'size'):
        sys.stdout.write('%d\n'%len(que))
    if (command[0] == 'empty'):
        if que: sys.stdout.write('%d\n'%0)
        else : sys.stdout.write('%d\n'%1)
    if (command[0] == 'front'):
        if que : sys.stdout.write('%d\n'%int(que[0]))
        else: sys.stdout.write('%d\n'%-1)
    if (command[0] == 'back'):
        if que : sys.stdout.write('%d\n'%int(que[-1]))
        else: sys.stdout.write('%d\n'%-1)