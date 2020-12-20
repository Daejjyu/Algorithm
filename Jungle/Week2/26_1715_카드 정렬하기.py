import heapq
import sys
N = int(sys.stdin.readline())
que = []

for i in range(N):
    num = int(sys.stdin.readline())
    heapq.heappush(que,num)

ans =0
if (N == 1):
    ans=0  #비교 필요 x
else:
    while(1):
        sum1=que[0]
        heapq.heappop(que)
        sum1+=que[0]
        heapq.heappop(que)
        ans += sum1
        if not (que):
            break
        heapq.heappush(que,sum1)

print(ans)