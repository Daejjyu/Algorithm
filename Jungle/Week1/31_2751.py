import sys
N = int(sys.stdin.readline())

list1 = []
for i in range(N):
    list1.append(int(input()))

list1.sort()

for i in list1:
    sys.stdout.write('%d\n' % i)
