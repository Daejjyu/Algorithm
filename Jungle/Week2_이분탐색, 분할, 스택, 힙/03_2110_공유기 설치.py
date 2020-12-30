N, C = map(int, input().split())
pos = []
for i in range(N):
    pos.append(int(input()))

pos.sort()

lo = 0
hi = pos[N-1]-pos[0]+1

while(lo+1 < hi):
    mid = int((lo+hi)/2)
    ans = 1
    cur = pos[0]
    for i in range(1, N):
        if(pos[i]-cur >= mid):  # 현재
            ans += 1
            cur = pos[i]
    if(ans >= C):  # 거리가 증가할수록 가능 개수가 작아지므로
        lo = mid
    else:
        hi = mid

print(lo)
