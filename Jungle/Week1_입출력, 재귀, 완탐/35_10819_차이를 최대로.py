from itertools import permutations

N = int(input())
list1 = list(map(int, input().split()))

ans = -1

for i in permutations(list1):
    temp = 0
    for j in range(N-1):
        temp += abs(i[j+1]-i[j])
    if(temp > ans):
        ans = temp

print(ans)
