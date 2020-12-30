list1 = []
sum1 = 0
for i in range(9):
    height = int(input())
    list1.append(height)
    sum1 += height

no1 = 0
no2 = 0
for i in range(0, 9):
    for j in range(i+1, 9):
        if(sum1 - list1[i] - list1[j] == 100):
            no1 = list1[i]
            no2 = list1[j]
            break
    if(no1):
        break

list1.sort()
for i in list1:
    if(i != no1 and i != no2):
        print(i)
