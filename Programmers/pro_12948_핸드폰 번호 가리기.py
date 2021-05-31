def solution(phone_number):    
    return phone_number[-4:].rjust(len(phone_number),'*')