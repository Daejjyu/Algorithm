import math
A, B, V = map(int, input().split())

ans = math.ceil((V-A)/(A-B))+1
print(ans)
