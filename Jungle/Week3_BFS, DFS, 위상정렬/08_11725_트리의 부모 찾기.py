import sys

sys.setrecursionlimit(50000)
r = sys.stdin.readline

N = int(r())
adj = [[] for r in range(N)]
for i in range(N - 1):
    u, v = map(int, r().split())
    adj[u - 1].append(v - 1)
    adj[v - 1].append(u - 1)
parent = [-1] * N
parent[0] = -2


def find(node):
    for i in adj[node]:
        if (parent[i] == -1):
            parent[i] = node
            find(i)


find(0)
for i in range(1, N):
    sys.stdout.write('%d\n' % (parent[i] + 1))
