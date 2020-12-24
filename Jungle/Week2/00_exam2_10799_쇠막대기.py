# pypy3
string = str(input())

ans = 0
stick_num = 0
for i in range(len(string)):
    if (string[i] == '('):
        stick_num += 1
    else:
        stick_num -= 1
        if (string[i - 1] == ')'):
            ans += 1
        else:
            ans += stick_num
print(ans)
