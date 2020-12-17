# pypy3
N = int(input())

num = []
strike = []
ball = []

for i in range(N):
    a, b, c = input().split()
    num.append(a)
    strike.append(int(b))
    ball.append(int(c))

ans = 0

for i in range(100, 999):  # 가능한 수
    i = str(i)
    if(i[0] == '0' or i[1] == '0' or i[2] == '0'):
        continue
    if(i[0] == i[1] or i[0] == i[2] or i[1] == i[2]):
        continue
    success = True
    for j in range(N):  # 질문 수
        if(success == False):
            break
        cnt_str = 0
        cnt_ball = 0
        for k in range(3):  # index1
            for p in range(3):  # index2
                if(num[j][k] == i[p]):
                    if(k == p):  # 자리수 같으면
                        cnt_str += 1
                    else:  # 자리수 다르면
                        cnt_ball += 1
        if(cnt_str != strike[j] or cnt_ball != ball[j]):
            success = False
    if(success):
        ans += 1
        # print(i)

print(ans)
