def solution(numbers):    
    answer = ''.join(map(str,sorted(numbers,key=lambda x: (str(x)*3),reverse=True)))
    return answer if answer[0]!='0' else '0'
