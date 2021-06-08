from collections import defaultdict
def solution(str1, str2):
    word_dict = defaultdict(int)
    str1 = str1.upper()
    str2 = str2.upper()
    union = []
    intersection=[]
    for i in range(1,len(str1)):
        if('A'<=str1[i-1]<='Z' and 'A'<=str1[i]<='Z'):
            word = str1[i-1]+str1[i]
            union.append(word)
            word_dict[word]+=1
    for i in range(1,len(str2)):
        if('A'<=str2[i-1]<='Z' and 'A'<=str2[i]<='Z'):
            word = str2[i-1]+str2[i]
            if(word_dict[word]>0):
                intersection.append(word)
                word_dict[word]-=1
            else:
                union.append(word)
    
    return int(len(intersection)/len(union)*65536) if len(union) !=0 else 65536