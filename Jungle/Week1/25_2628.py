w, h = map(int, input().split())
T = int(input())

row = [0, h]
col = [0, w]

for i in range(0, T):
    way, num = map(int, input().split())
    if (way == 0):
        row.append(num)
    else:
        col.append(num)

row.sort()
col.sort()

list_h = []
list_w = []

for i in range(0, len(row)-1):
    list_h.append(row[i+1] - row[i])
for i in range(0, len(col)-1):
    list_w.append(col[i+1] - col[i])

ans = -1
for i in list_h:
    for j in list_w:
        if(i*j > ans):
            ans = i*j
print(ans)
