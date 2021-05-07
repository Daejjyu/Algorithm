def solution(numbers): 
    numbers = list(map(str, numbers))
    return str(int(''.join(sorted(numbers,key = lambda x: x*3, reverse=True))))
    # 3자리를 비교해야 하므로 x*3