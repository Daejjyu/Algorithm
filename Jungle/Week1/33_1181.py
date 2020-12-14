import sys
N = int(sys.stdin.readline())

list1 = set()
for i in range(N):
    list1.add(sys.stdin.readline().split()[0])

list1 = list(list1)
list1.sort()
list1.sort(key=lambda x: len(x))

for i in list1:
    print(i)
