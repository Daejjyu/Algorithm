A, B, C = map(int, input().split())

ans=0

def remainder(cnt):
    if(cnt<=0):
        return 1
    ret=0
    temp = remainder(int(cnt/2))
    global ans
    ans = temp * temp % C
    if(cnt%2): #홀수이면
        ans = (ans*A)%C
    return ans

print(remainder(B))
