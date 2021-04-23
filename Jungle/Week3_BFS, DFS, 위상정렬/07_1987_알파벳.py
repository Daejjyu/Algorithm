import sys

ans = 0


# 1. alphabet
# def solve():
#     r = sys.stdin.readline
#     R, C = map(int, r().split())
#
#     map1 = [list(r().strip()) for _ in range(R)]
#     alpha = [0] * 26
#
#     dR = [0, 0, 1, -1]
#     dC = [1, -1, 0, 0]
#
#     def dfs(r, c, cnt):
#         global ans
#         ans = max(cnt, ans)
#         # print(r, c)
#         for i in range(4):
#             nextR = r + dR[i]
#             nextC = c + dC[i]
#             if (nextR < 0 or nextC < 0 or nextR >= R or nextC >= C):
#                 continue
#             nextChar = ord(map1[nextR][nextC]) - ord('A')
#             if (alpha[nextChar] == 0):
#                 alpha[nextChar] = 1
#                 dfs(nextR, nextC, cnt + 1)
#                 alpha[nextChar] = 0
#
#     alpha[ord(map1[0][0]) - ord('A')] = 1
#     dfs(0, 0, 1)
#
#     sys.stdout.write('%d' % ans)
#
#
# solve()

# 2. string
def solve():
    input = sys.stdin.readline

    R, C = map(int, input().split())
    terrain = [list(input().strip()) for _ in range(R)]
    cmd = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    ans = 0
    # dR = [1, -1, 0, 0]
    # dC = [0, 0, 1, -1]
    que = set()
    que.add((0, 0, terrain[0][0]))  # r c string

    while que:
        top_r, top_c, top_s = que.pop()
        ans = max(ans, len(top_s))
        # for r, c in zip(dR, dC):
        #     nextR = top_r + r
        #     nextC = top_c + c
        for r, c in cmd:
            nextR, nextC = top_r + r, top_c + c
            if (0 <= nextR < R and 0 <= nextC < C and terrain[nextR][nextC] not in top_s):
                # if (nextR < 0 or nextC < 0 or nextR >= R or nextC >= C):
                #     continue
                # if (terrain[nextR][nextC] in top_s):
                #     continue
                que.add((nextR, nextC, top_s + terrain[nextR][nextC]))
    print(ans)


solve()
