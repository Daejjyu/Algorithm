def impossible(answer):
    pillar,bo=0,1
    for x,y,a in answer:
        if a == pillar: 
            if y != 0 and (x, y-1, pillar) not in answer and \
        (x-1, y, bo) not in answer and (x, y, bo) not in answer:
                return True
        else:
            if (x, y-1, pillar) not in answer and (x+1, y-1, pillar) not in answer and \
        not ((x-1, y, bo) in answer and (x+1, y, bo) in answer):
                return True        
    return False

def solution(n, build_frame):
    answer = set()
    for x,y,a,b in build_frame:
        elem = (x,y,a)
        if(b):
            answer.add(elem)
            if impossible(answer):
                answer.remove(elem)
        elif elem in answer:
            answer.remove(elem)
            if impossible(answer):
                answer.add(elem)            
    return sorted(list(answer),key=lambda x: (x[0],x[1],x[2]))