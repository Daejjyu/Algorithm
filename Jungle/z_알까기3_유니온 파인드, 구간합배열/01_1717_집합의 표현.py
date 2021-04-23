import sys

def solve():
    input = sys.stdin.readline
    N,M = map(int,input().split())

    parent = [-1]*(N+1)

    def union(A,B):
        A = find(A)
        B = find(B)
        if(A==B):
            return
        parent[B] = A
        # if(abs(A)>abs(B)):#getSize
        #     parent[A]+=parent[B]
        #     parent[B]=A
        # else:
        #     parent[B]+=parent[A]
        #     parent[A]=B

    def find(N):
        if(parent[N]<0):
            return N
        parent[N] = find(parent[N])
        return parent[N]

    for _ in range(M):
        UF,A,B = map(int,input().split())
        if(UF):
            if(find(A)==find(B)):
                print('YES')
            else:
                print('NO')
        else:
            union(A,B)
solve()