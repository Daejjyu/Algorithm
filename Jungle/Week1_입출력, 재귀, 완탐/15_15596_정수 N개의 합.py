# a = list(map(int, input().split()))

def solve(a):
    ans = 0
    for i in range(0, len(a)):
        ans += a[i]

    return ans


# print(solve())
