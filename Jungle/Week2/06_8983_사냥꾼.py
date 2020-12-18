M, N, L = map(int, input().split())

list1 = list(map(int, input().split()))

list1.sort()
for i in range(N):
    A, B = map(int, input().split())
    lo = 0
    hi = M
    while(lo+1 < hi):
        mid = int((lo+hi)/2)
        if(list1[mid] > A):
            lo = mid
        else:
            hi = mid
        print(list1[lo], list1[hi])
