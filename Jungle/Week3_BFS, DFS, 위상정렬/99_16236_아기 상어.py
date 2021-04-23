import sys
input = sys.stdin.readline

N = int(input())
terrain = [list(map(int,input().split())) for _ in range(N)]

for i in range