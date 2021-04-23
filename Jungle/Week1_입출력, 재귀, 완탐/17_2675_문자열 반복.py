T = int(input())

for i in range(0, T):
    list1 = list(input())
    rep = int(list1[0])
    ans = ''
    for j in range(2, len(list1)):
        ans += list1[j]*rep
    print(ans)
