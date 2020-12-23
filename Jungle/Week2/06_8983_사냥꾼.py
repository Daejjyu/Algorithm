M, N, L = map(int, input().split())
pos = list(map(int, input().split()))
pos.sort()

ans = 0
for i in range(N):
    x, y = map(int, input().split())
    lo = 0
    hi = M - 1
    while (lo + 1 < hi):
        mid = int((lo + hi) / 2)
        if (pos[mid] <= x):
            lo = mid
        else:
            hi = mid
    if ((abs(x - pos[lo]) + y <= L) or (abs(x - pos[hi]) + y <= L)):
        ans += 1
print(ans)
