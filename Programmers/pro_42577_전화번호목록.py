def solution(phone_book):
    hash_map = {}
    for phone_num in phone_book:
        hash_map[phone_num]=1
    for phone_num in phone_book:
        temp=""
        for number in phone_num:
            temp +=number
            if temp in hash_map and temp!=phone_num:
                return False
    return True