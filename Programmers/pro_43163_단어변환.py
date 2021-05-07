from collections import deque,defaultdict
visited=defaultdict(int)

def solution(begin, target, words):    
    que = deque()
    que.append(begin)
    answer = -1
    while que:
        answer+=1
        for i in range(len(que)):
            cur = que.popleft()
            visited[cur]=1
            if(cur==target):
                return answer
            for word in words:
                if(visited[word]==0):
                    diff=0
                    for a,b in zip(cur,word):
                        if(a!=b):
                            diff+=1
                        if(diff>1):
                            break
                    if(diff==1):
                        que.append(word)        
    return 0