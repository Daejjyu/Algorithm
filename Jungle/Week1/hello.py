def convert_num(x: int, r: int) -> str:
    # 정수값 x를 r진수로 변환한 뒤 그 수를 나타내는 문자열을 반환
    d = ''
    dchar = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'

    while(x > 0):
        d += dchar[x % r]
        x //= r

    return d[::-1]


print(convert_num(360, 11))
