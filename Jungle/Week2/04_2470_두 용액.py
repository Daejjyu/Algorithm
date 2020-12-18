import sys
N = int(input())
list1 = list(map(int, sys.stdin.readline().split()))

list1.sort(key=lambda x: abs(x))

ans = 1e10+1
ans1 = 0
ans2 = 0
for i in range(N-1):
    if(abs(list1[i]+list1[i+1]) < ans):
        ans1 = list1[i]
        ans2 = list1[i+1]
        ans = abs(list1[i]+list1[i+1])
if(ans1 > ans2):
    ans1, ans2 = ans2, ans1
print(ans1, ans2)
