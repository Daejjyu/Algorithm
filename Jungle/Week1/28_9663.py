N = int(input())

rowUsed = [0]*N
queenRowPosAt = [-1]*N
ans = 0


def isCross(col):  # 이전 col들과 대각선 겹치는지 검사
    if(col == 0):
        return False  # 이전 col이 없으므로
    else:
        for i in range(col):
            # [col 값 차이 == row 값 차이]면 대각선 겹침
            if(col - i == abs(queenRowPosAt[col]-queenRowPosAt[i])):
                return True
        return False


def nQueen(col):  # [조건 1. col 위치 다를 것. col 증가시키며 재귀]
    for i in range(N):
        if(rowUsed[i] == 0):  # [조건 2. 이전 col과 row 위치 다를 것]
            queenRowPosAt[col] = i

            if (isCross(col)):  # [조건 3. 이전 col과 대각선 위치 다를 것.]
                continue

            if(col == N-1):
                global ans
                ans += 1
            else:
                rowUsed[i] = 1
                nQueen(col+1)
                rowUsed[i] = 0


nQueen(0)
print(ans)
