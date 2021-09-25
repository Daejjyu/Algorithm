def solution(n, s):
    if s<n:
        return [-1]
    elif s%n:
        return [s//n]*(n-s%n) + [(s//n)+1]*(s%n)
    else:
        return [s//n]*n