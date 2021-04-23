# pypy3
N = int(input())

map1 = [0] * N

for i in range(N):
    map1[i] = list(map(int, input()))


def quad_tree(size, r, c):
    flag = True
    half = int(size / 2)
    cur_num = map1[r][c]

    for i in range(r, r + size):
        for j in range(c, c + size):
            if (map1[i][j] != cur_num):
                flag = False
                break
        if (flag == False):
            break

    if (flag):
        print(cur_num, end='')
    else:
        print('(', end='')
        quad_tree(half, r, c)
        quad_tree(half, r, c + half)
        quad_tree(half, r + half, c)
        quad_tree(half, r + half, c + half)
        print(')', end='')


quad_tree(N, 0, 0)
