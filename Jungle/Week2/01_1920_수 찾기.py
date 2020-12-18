# 이분탐색 대신 set 사용
N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))

A = set(A)

for i in B:
    if i in A:
        print(1)
    else:
        print(0)
