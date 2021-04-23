A, B, C = map(int, input().split())


def remainder(cnt):
    if (cnt <= 0):
        return 1
    temp = remainder(int(cnt / 2))
    ans = temp * temp % C
    if (cnt % 2):  # 홀수이면
        ans = (ans * A) % C
    return ans


print(remainder(B))
