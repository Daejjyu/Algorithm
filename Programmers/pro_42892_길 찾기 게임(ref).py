# https://velog.io/@dowon938/프로그래머스길-찾기-게임-JS
from collections import deque
import sys
sys.setrecursionlimit(10**6)

def solution(nodeinfo):
    pre=[]
    post=[]
    nodeinfo = deque(sorted([[v[0],v[1],k+1] for k,v in enumerate(nodeinfo)],key=lambda x: (-x[1],x[0])))
    def split(nodeinfo):
        if not nodeinfo:
            return
        else:
            parentX,parentY,parentNum = nodeinfo.popleft()
            left = deque(filter(lambda x: x[0]<parentX,nodeinfo))
            right = deque(filter(lambda x: x[0]>parentX,nodeinfo))            
            pre.append(parentNum)
            split(left)
            split(right)
            post.append(parentNum)
    split(nodeinfo)
    return [pre,post]