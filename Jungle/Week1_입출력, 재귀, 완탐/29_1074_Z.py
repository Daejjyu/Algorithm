N, r, c = map(int, input().split())


def divide(size, r, c):
    idx = 0
    if(size == 2):
        return r*2+c*1
    half = int(size/2)
    if(r < half and c < half):
        return idx + divide(half, r, c)
    elif(r < half and c >= half):
        idx += int(size*size/4)
        return idx + divide(half, r, c-half)
    elif(r >= half and c < half):
        idx += int(size*size/4*2)
        return idx + divide(half, r-half, c)
    elif(r >= half and c >= half):
        idx += int(size*size/4*3)
        return idx + divide(half, r-half, c-half)


print(divide(1 << N, r, c))
