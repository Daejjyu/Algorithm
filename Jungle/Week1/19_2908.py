a, b = map(int, input().split())

a = str(a)
b = str(b)

for i in range(0, 3):
    if(a[2-i] == b[2-i]):
        continue
    if(a[2-i] > b[2-i]):
        ans = a
        break
    else:
        ans = b
        break

for i in range(0, 3):
    print(ans[2-i], end='')
