import sys

input = sys.stdin.readline

N = int(input())
list1 = list(map(int, input().split()))

ans = 0
temp = 0
max_minus = -float('inf')
zero = False
for i in range(N):
    temp += list1[i]
    if (temp < 0):
        temp = 0
    if (list1[i] < 0):
        max_minus = max(max_minus, list1[i])
    if (list1[i] == 0):
        zero = True
    ans = max(ans, temp)
if (ans == 0):
    if (zero):
        print(0)
    else:
        print(max_minus)
else:
    print(ans)
