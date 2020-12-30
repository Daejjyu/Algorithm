import sys
N = int(sys.stdin.readline())

for i in range(N):
    command = input()
    cnt =0
    for j in range(len(command)):
        if (command[j] == '('):
            cnt+=1
        if(command[j]==')'):
            cnt-=1
        if(cnt<0):
            break
    if(cnt!=0):
        sys.stdout.write('NO\n')
    else:
        sys.stdout.write('YES\n')

