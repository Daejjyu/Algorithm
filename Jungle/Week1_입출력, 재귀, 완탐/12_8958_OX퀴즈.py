T = int(input())

for i in range(0, T):
    list1 = list(input())
    ans = 0
    cur = 0
    for j in range(0, len(list1)):
        if(list1[j] == 'O'):
            cur += 1
            ans += cur
        else:
            cur = 0
    print(ans)
