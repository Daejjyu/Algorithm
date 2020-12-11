N = int(input())


def Hanoi(n, start, left, end):  # 5, 1, 2, 3

    if(n == 1):
        print(start, end)
        return

    Hanoi(n-1, start, end, left)
    Hanoi(1, start, left, end)
    Hanoi(n-1, left, start, end)


print((1 << N) - 1)
if(N < 21):
    Hanoi(N, 1, 2, 3)
