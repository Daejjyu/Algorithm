list1 = [sum(map(int, x.split('+'))) for x in input().split('-')]
print(list1[0] - sum(list1[1:]))

# input = str(sys.stdin.readline().strip())
#
# ans = 0
# cur = ''
# plus = True
# for i in input:
#     if ('0' <= i <= '9'):
#         cur += i
#     elif (i == '+'):
#         if (plus):
#             ans += int(cur)
#         else:
#             ans -= int(cur)
#         cur = ''
#     elif (i == '-'):
#         if (plus):
#             ans += int(cur)
#         else:
#             ans -= int(cur)
#         cur = ''
#         plus = False
# if (plus):
#     ans += int(cur)
# else:
#     ans -= int(cur)
# print(ans)
