N, X = map(int, input().split())
list1 = list(map(int, input().split()))

for i in range(0, N):
    if list1[i] < X:
        print(list1[i], end=' ')
