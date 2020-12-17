# pypy3
N = int(input())

visited = []
visited.append(N)

ans = 0
while(1):
    if(ans > 0 and N == visited[0]):
        break
    origin1 = N % 10
    origin10 = N//10
    new = origin1+origin10
    # print('new', new)
    nextN = origin1*10 + new % 10
    visited.append(nextN)
    # print('nextN', nextN)
    N = nextN
    ans += 1
print(ans)
