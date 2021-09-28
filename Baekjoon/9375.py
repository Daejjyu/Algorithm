import sys
from collections import defaultdict

def solution():
  input = sys.stdin.readline
  T = int(input())
  while(T):
    T-=1
    N = int(input())
    cateDict = defaultdict(list)
    cateSet = set()
    while(N):
      N-=1
      clothes, category = input().split()
      cateDict[category].append(clothes)
      cateSet.add(category)
    acc=1
    for category in cateSet:
      acc *= len(cateDict[category])+1
    print(acc-1)

solution()