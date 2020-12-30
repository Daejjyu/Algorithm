import sys

R, C = map(int, sys.stdin.readline().split())
map = [list(map(str, sys.stdin.readline().rstrip())) for _ in range(R)]  # 아스키코드 값으로 전부 변환해서 저장'


def solve():
    visited = [[False for i in range(C)] for i in range(R)]
    visited_alphabet = [False] * 26
    global count
    global result
    dr = [0, 0, 1, -1]
    dc = [1, -1, 0, 0]
    count = 0
    result = 0

    def dfs(map, r, c, visited, visited_alphabet):
        global count
        global result
        visited[r][c] = True
        visited_alphabet[ord(map[r][c]) - 65] = True
        count += 1
        result = max(count, result)
        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]
            if 0 <= nr < R and 0 <= nc < C and visited[nr][nc] == False and visited_alphabet[
                ord(map[nr][nc]) - 65] == False:
                visited[nr][nc] = True
                visited_alphabet[ord(map[nr][nc]) - 65] = True
                dfs(map, nr, nc, visited, visited_alphabet)
                visited[nr][nc] = False
                visited_alphabet[ord(map[nr][nc]) - 65] = False
                count -= 1

    dfs(map, 0, 0, visited, visited_alphabet)
    print(result)


solve()
