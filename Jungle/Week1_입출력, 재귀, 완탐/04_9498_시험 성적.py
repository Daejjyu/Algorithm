score = int(input())

cut = (90, 80, 70, 60, 0)
grade = ('A', 'B', 'C', 'D', 'F')

for i in range(0, 6):
    if(score >= cut[i]):
        print(grade[i])
        break
