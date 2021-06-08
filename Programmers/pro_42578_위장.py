def solution(clothes):
    from collections import Counter
    from functools import reduce
    
    cnt = Counter([kind for name, kind in clothes])
    answer = reduce(lambda acc,cur: acc *(cur+1),cnt.values(),1)-1
    return answer

# def solution(clothes):
#     dict_clothes = {}
#     cnt=0
#     for i,j in clothes:
#         if(dict_clothes.get(j)):
#             dict_clothes[j]+=1
#         else:
#             dict_clothes[j]=1
#             cnt+=1
#     answer=1
#     for i, j in dict_clothes.items():
#         answer*=(j+1)
#     return answer-1