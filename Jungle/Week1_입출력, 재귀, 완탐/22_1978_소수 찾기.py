eratos = [1]*1001
eratos[0] = 0  # init
eratos[1] = 0  # init

for i in range(2, 1000):
    if(eratos[i] == 1):
        j = 2
        while(i*j <= 1000):
            eratos[i*j] = 0
            j += 1

N = input()
input_list = map(int, input().split())

ans = 0
for i in input_list:
    if(eratos[i] == 1):
        ans += 1

print(ans)
