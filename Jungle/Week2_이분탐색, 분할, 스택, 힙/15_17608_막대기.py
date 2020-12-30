import sys
N = int(sys.stdin.readline())
list = []

for i in range(N):
    list.append(int(sys.stdin.readline()))


cur = list[N-1]
ans = 1
for i in range(1,N):
    if(list[N-1-i]>cur):
        cur = list[N-1-i]
        ans+=1

print(ans)