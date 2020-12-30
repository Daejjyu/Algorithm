N = int(input())

map1 = [0]*N
for i in range(N):
    map1[i] = list(map(int, input().split()))

ans = [0, 0]


def cut(size, r, c):
    color = map1[r][c]
    flag = True
    for i in range(r, r+size):
        if(flag != True):
            break
        for j in range(c, c+size):
            if(map1[i][j] != color):
                flag = False
                break

    if(flag):
        ans[color] += 1
        return
    half = int(size/2)
    cut(half, r, c)
    cut(half, r, c+half)
    cut(half, r+half, c)
    cut(half, r+half, c+half)


cut(N, 0, 0)
print(ans[0])
print(ans[1])
