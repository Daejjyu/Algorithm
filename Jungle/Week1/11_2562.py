idx = -1
ans = -1
for i in range(0, 9):
    num = int(input())
    if(num > ans):
        ans = num
        idx = i

print(ans, idx+1, sep='\n')
