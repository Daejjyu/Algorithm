import sys
sys.setrecursionlimit(100000) 

def solution(nodeinfo):
    nodelist = [[x[1][0],x[0]+1 ] for x in sorted(enumerate(nodeinfo),key=lambda x: (-x[1][1],x[1][0]))]
    preorder, postorder = [],[]
    def dfs(nodeList):
        if not nodeList:
            return
        topX, topIdx = nodeList[0]
        left,right = [],[]
        for node in nodeList:
            if(node[0]<topX):
                left.append(node)
            elif(node[0]>topX):
                right.append(node)        
        preorder.append(topIdx)
        dfs(left)
        dfs(right)
        postorder.append(topIdx)
    dfs(nodelist)
    return [preorder,postorder]