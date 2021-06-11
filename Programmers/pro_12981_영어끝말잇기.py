from collections import defaultdict
def solution(n, words):
    word_dict = defaultdict(int)
    for i in range(len(words)):
        word_dict[words[i]]+=1
        if(i>0 and words[i-1][-1] != words[i][0] or word_dict[words[i]]>1):
            return [i%n+1,i//n+1]
    return [0,0]