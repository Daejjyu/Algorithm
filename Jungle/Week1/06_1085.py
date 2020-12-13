x, y, w, h = map(int, input().split())

ans = 1e9

dist = [x, y, w-x, h-y]

for i in dist:
    if(i < ans):
        ans = i

print(ans)
