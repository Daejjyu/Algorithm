# https://gist.github.com/inspirit941/6e609f0bcfcb48f4e5a55fb348ba12d0
# maxheap(left) - target - minheap(right)
# [0, n-1] row
import heapq
def solution(n, k, cmd):
    left=[]
    right=[]
    for i in range(k):
        heapq.heappush(left,-i)
    for i in range(k,n):
        heapq.heappush(right,i)
        
    delete=[]
    for s in cmd:
        s = s.split(' ')
        if s[0]=='U':
            move = int(s[1])
            for _ in range(move):
                if left:
                    heapq.heappush(right,-heapq.heappop(left))
        elif s[0]=='D':
            move = int(s[1])
            for _ in range(move):
                if right:
                    heapq.heappush(left,-heapq.heappop(right))
        elif s[0]=='C':
            delete.append(heapq.heappop(right))
            if not right:
                heapq.heappush(right,-heapq.heappop(left))
        elif s[0]=='Z':
            restore = delete.pop()
            if restore < right[0]:
                heapq.heappush(left,-restore)
            else:
                heapq.heappush(right,restore)
                
    result = ['O']*n
    for i in delete:
        result[i]='X'    
    return "".join(result)