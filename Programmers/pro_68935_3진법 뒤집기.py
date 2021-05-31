def solution(n):
    ternary = ''
    while(n):
        ternary+=str(n%3)
        n//=3
    print(ternary)
    return int(ternary,3)