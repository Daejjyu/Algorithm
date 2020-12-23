N = int(input())
list1 = list(map(int, input().split()))
list1.sort()

# 1. 투 포인터
lo = 0
hi = N - 1
ans = 2e9 + 1
num1 = 0
num2 = 0
while (lo < hi):
    val = list1[lo] + list1[hi]
    if (abs(val) < ans):
        ans = abs(val)
        num1 = list1[lo]
        num2 = list1[hi]
        if (val == 0):
            break
    if (val < 0):
        lo += 1
    else:
        hi -= 1
print(num1, num2)

# # 2. 절댓값 sort
# num1 = 0
# num2 = 0
# ans = 2e9 + 1
# list1.sort(key=lambda x: abs(x))
# for i in range(1, N):
#     val = list1[i - 1] + list1[i]
#     if (abs(val) < ans):
#         ans = abs(val)
#         num1 = list1[i - 1]
#         num2 = list1[i]
#         if (val == 0):
#             break
# if (num1 > num2): num1, num2 = num2, num1
# print(num1, num2)
