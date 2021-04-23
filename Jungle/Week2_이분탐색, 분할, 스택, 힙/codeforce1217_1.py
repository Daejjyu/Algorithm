N = int(input())

for i in range(N):
    A, B, C = map(int, input().split())
    sum1 = A+B+C
    mok = int(sum1/9)
    if(sum1 % 9 == 0 and A >= mok and B >= mok and C >= mok):
        print('YES')
    else:
        print('NO')
