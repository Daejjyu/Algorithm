import heapq
import sys
N = int(sys.stdin.readline())
que = []

for i in range(N):
    num = int(sys.stdin.readline())
    if(num==0):
        if(que):
            sys.stdout.write('%d\n'%que[0][1])
            if(len(que)==1):
                que=[]
            else:
                heapq.heappop(que)
        else:
            sys.stdout.write('%d\n'%0)
    else:
        heapq.heappush(que,(-num,num))

