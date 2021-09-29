import sys
input = sys.stdin.readline

def solution():
  D, N, M  = map(int,input().split())
  stones = [D]
  while(N):
    N-=1
    stones.append(int(input()))
  stones.sort()
  lo = 0
  hi = D+1
  while(lo+1<hi):
    mid = (lo+hi)//2
    pos = 0
    cnt = 0
    for x in stones:
      if(mid>x-pos):
        cnt+=1      
        if(cnt>M):
          break
      else:
        pos=x
    if(cnt<=M):
      lo=mid
    else:
      hi=mid
  print(lo)
solution()