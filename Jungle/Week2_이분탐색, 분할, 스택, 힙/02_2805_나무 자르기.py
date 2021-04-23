N, M = map(int, input().split())
tree = list(map(int, input().split()))

lo = 0
hi = 1e9+1

while(lo+1 < hi):
    mid = int((lo+hi)//2)  # len
    sum1 = 0
    for i in range(N):
        sum1 += max(0, tree[i] - mid)
    if(sum1 >= M):
        lo = mid
    else:
        hi = mid
print(lo)
