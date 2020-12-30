eratos = [1]*10001
eratos[0] = 0  # init
eratos[1] = 0  # init

for i in range(2, 10000):
    if(eratos[i] == 1):
        j = 2
        while(i*j <= 10000):
            eratos[i*j] = 0
            j += 1


T = int(input())

for i in range(0, T):
    num = int(input())
    ans1 = -1
    ans2 = -1
    for j in range(2, int(num/2)+1):
        if(eratos[j] and eratos[num-j]):
            ans1 = j
            ans2 = num-j
    print(ans1, ans2)
