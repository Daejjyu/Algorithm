import sys

ans = 0


def solve():
    r = sys.stdin.readline
    R, C = map(int, r().split())

    map1 = [list(r().strip()) for _ in range(R)]
    alpha = [0] * 26

    dR = [0, 0, 1, -1]
    dC = [1, -1, 0, 0]

    def dfs(r, c, cnt):
        global ans
        ans = max(cnt, ans)
        # print(r, c)
        for i in range(4):
            nextR = r + dR[i]
            nextC = c + dC[i]
            if (nextR < 0 or nextC < 0 or nextR >= R or nextC >= C):
                continue
            nextChar = ord(map1[nextR][nextC]) - ord('A')
            if (alpha[nextChar] == 0):
                alpha[nextChar] = 1
                dfs(nextR, nextC, cnt + 1)
                alpha[nextChar] = 0

    alpha[ord(map1[0][0]) - ord('A')] = 1
    dfs(0, 0, 1)

    sys.stdout.write('%d' % ans)


solve()
