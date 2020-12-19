string = str(input())

ans1=0
ans2=0
cur ='0'
ans = []
for i in string:
    if(i=='(' or i=='['):
        if(cur == i):
            ans.append('*')
        else:
            ans.append('+')
            cur = i
        if(i=='('):
            ans.append(2)
            ans1+=1
        else:
            ans.append(3)
            ans2+=1
    elif(i==')'):
        ans1-=1
    else:
        ans2-=1
    if(ans1<0 or ans2<0):
        break

if(ans1<0 or ans2<0):
    print(0)
else:
    print(ans)
