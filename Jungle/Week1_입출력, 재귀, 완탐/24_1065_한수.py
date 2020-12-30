hansu = [0]*1001
for i in range(1, 100):
    hansu[i] = 1
for i in range(100, 1000):
    a = int(i % 10)  # 1
    b = int((i/10) % 10)  # 10
    c = int(i/100)  # 100
    if(a-b == b-c):
        hansu[i] = 1

num = int(input())
ans = 0
for i in range(1, num+1):
    if(hansu[i] == 1):
        ans += 1
print(ans)
