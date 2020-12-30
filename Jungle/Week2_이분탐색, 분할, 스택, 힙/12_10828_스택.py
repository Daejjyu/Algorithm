import sys
N = int(sys.stdin.readline())

stack = []

for i in range(N):
    command = list(sys.stdin.readline().split())
    if(command[0] == 'push'):
        stack.append((command[1]))
    if (command[0] == 'top'):
        if stack: sys.stdout.write('%d\n'%int(stack[-1]))
        else: sys.stdout.write('%d\n'%-1)
    if (command[0] == 'size'):
        sys.stdout.write('%d\n'%len(stack))
    if (command[0] == 'empty'):
        if stack: sys.stdout.write('%d\n'%0)
        else: sys.stdout.write('%d\n'%1)
    if (command[0] == 'pop'):
        if stack:
            sys.stdout.write('%d\n' % int(stack[-1]))
            stack.pop()
        else:
            sys.stdout.write('%d\n'%-1)
