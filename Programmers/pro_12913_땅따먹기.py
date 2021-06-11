def solution(land):
    for r in range(1,len(land)):
        for c in range(4):
            land[r][c]=land[r][c]+max(land[r-1][(c+1)%4],land[r-1][(c+2)%4],land[r-1][(c+3)%4])
    return max(land[-1])
