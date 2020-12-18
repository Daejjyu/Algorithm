M, N, L = map(int, input().split())

list1 = list(map(int, input().split()))

ans = 0
list1.sort()
for i in range(N):
    A, B = map(int, input().split())
    lo = 0
    hi = M-1
    while(lo+1 < hi):  # x좌표의 상 하한 찾기
        mid = int((lo+hi)/2)
        if(list1[mid] <= A):
            lo = mid
        else:
            hi = mid
    if(B+abs(list1[lo]-A) <= L or (B+abs(list1[hi]-A) <= L)):  # 거리 비교
        ans += 1
print(ans)
