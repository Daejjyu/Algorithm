import sys
def solve():
    input = sys.stdin.readline

    N,M,K = map(int,input().split())
    parent = list(map(lambda x:x* -1, map(int,input().split())))
    def find(n):
        if(parent[n]<0):
            return n
        parent[n]=find(parent[n])
        return parent[n]

    def union(a,b):
        a = find(a) #index of root
        b = find(b)
        if (a == b):
            return
        if(abs(parent[a])<abs(parent[b])): #size of root
            parent[b]=a
        else:
            parent[a]=b

    for _ in range(M):
        v,w = map(int,input().split())
        union(v-1,w-1)

    dict={}
    ans =0

    for i in range(N):
        if(dict.get(find(i))==None):
            dict[find(i)]=1
            ans +=abs(parent[find(i)])
            if(ans>K):
                print("Oh no")
                quit()
    print(ans)
solve()