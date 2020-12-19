N, K  = map(int,input().split())
num = list(str(input()))
num.sort()
for i in range(N-1,K-1,-1):
    print(num[i],end='')
if(N-1==K-1):
    print(0)