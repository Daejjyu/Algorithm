import sys
N = int(sys.stdin.readline())

list1 = [0]*10001
for i in range(N):
    list1[int(sys.stdin.readline())] += 1

for i in range(1, 10001):
    sys.stdout.write('%d\n' % i * list1[i])
