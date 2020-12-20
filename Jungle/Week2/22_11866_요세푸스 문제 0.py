N, K = map(int,input().split())

list1 = []

for i in range(N):
    list1.append(i+1)

print('<',end='')
idx=0
while(1):
    if(len(list1)==1):
        print(f'%d>' % list1[0], end='')
        break
    idx+=K-1
    idx%=len(list1)
    print(f'%d, '%list1[idx],end='')
    list1.pop(idx)

