def solution(answers):
    stu1=[1,2,3,4,5]#5
    stu2=[2,1,2,3,2,4,2,5]#8
    stu3=[3,3,1,1,2,2,4,4,5,5]#10
    ans=[0,0,0]
    for i in range(len(answers)):
        if(answers[i]==stu1[i%5]):
            ans[0]+=1
        if(answers[i]==stu2[i%8]):
            ans[1]+=1
        if(answers[i]==stu3[i%10]):    
            ans[2]+=1
            
    m=max(ans) 
    for i in range(len(ans)):
        if(m==ans[i]):
            ans.append(i+1)
    return ans[3:]