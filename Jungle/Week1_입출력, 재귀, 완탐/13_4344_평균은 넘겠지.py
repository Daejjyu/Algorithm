C = int(input())
for i in range(0, C):
    list1 = list(map(int, input().split()))
    sum1 = 0
    for j in range(1, len(list1)):
        sum1 += list1[j]
    mean1 = sum1/list1[0]
    ans1 = 0
    for j in range(1, len(list1)):
        if(list1[j] > mean1):
            ans1 += 1
    print('%.3f' % round(ans1/list1[0]*100, 3), '%', sep='')
