N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))

# 1. 이분탐색 코드
A.sort()
for i in B:
    lo = 0
    hi = N
    while (lo + 1 < hi):
        mid = int((lo + hi) / 2)
        if (A[mid] <= i):
            lo = mid
        else:
            hi = mid
    if (A[lo] == i):
        print(1)
    else:
        print(0)

# #2. set 사용
# A = set(A)
#
# for i in B:
#     if i in A:
#         print(1)
#     else:
#         print(0)
