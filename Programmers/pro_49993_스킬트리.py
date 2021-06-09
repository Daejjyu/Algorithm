def solution(skill, skill_trees):
    answer = 0
    def key(x):
        return skill.index(x)
    for i in skill_trees:
        cmp_trees = [x for x in i if x in skill]
        cmp_str=''.join(cmp_trees)
        if(cmp_str == ''.join(sorted(cmp_trees,key=lambda x:key(x)))):
            if(skill[:len(cmp_trees)]==cmp_str):
                answer+=1
    return answer