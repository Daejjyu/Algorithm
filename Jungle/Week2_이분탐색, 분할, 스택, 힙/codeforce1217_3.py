# fail
T = int(input())
for i in range(T):
    N = int(input())
    dr = 0
    pos1 = 0
    pos2 = 0
    ans = 0
    time = []
    command = []
    timeleft = 0
    for j in range(N):
        time1, command1 = map(int, input().split())
        time.append(time1)
        command.append(command1)
    for j in range(N):
        time3 = timeleft
        if(j > 0):
            print('\nloop#', j)
            print('before', time[j-1], command[j-1])
            print('cur', time[j], command[j])

            timesleep = min(timeleft, time[j]-time[j-1])
            print('timeleft bf', timeleft)
            timeleft -= timesleep
            print('timeleft af', timeleft)
            pos2 = pos1+timesleep*dr
            print('pos1, pos2, dr', pos1, pos2, dr)

            if(pos1 <= command[j-1] <= pos2):
                ans += 1
                print('ans', ans)
            pos1 = pos2

        # check command do
        if(j == 0 or time[j-1]+time3 <= time[j]):
            print('in')
            if(j == N-1):
                ans += 1
                print('ans', ans)
            if(command[j] > pos1):
                dr = 1
            elif(command[j] < pos1):
                dr = -1
            else:
                dr = 0

            timeleft = abs(command[j]-pos1)
            if(j == 0):
                pos1 = 0
            else:
                pos1 = command[j-1]  # 여기 실수.
    print('ans', ans)
