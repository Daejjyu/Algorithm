import sys
sys.setrecursionlimit(50000000)

A, B, C = map(int, input().split())


def Remainder(cnt):
    if(cnt%2):
        
    print('in')
    if(cnt == 1):
        ans = 1
    if(cnt>1):
        temp = Remainder(int(cnt/2))
    if(cnt==1):
        temp = 1
    ans = (temp * temp) % C
    if(cnt % 2):
        print(ans, A, C)
        ans = (ans * A) % C
    return ans

print(Remainder(B))
