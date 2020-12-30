a = int(input())
b = int(input())
c = int(input())

mul = a*b*c
list1 = list(map(int, list(str(mul))))

ans1 = [0]*10

for i in list1:
    ans1[i] += 1

for i in range(0, 10):
    print(ans1[i])
