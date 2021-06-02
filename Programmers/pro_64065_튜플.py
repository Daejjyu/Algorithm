def solution(s):
    list1 = [0]*1500  # 2000000**0.5 + a
    maxN=0
    temp=[]
    num=""
    for i in s[:-1]:
        if(i.isdigit()):
            num+=i
        if(i==','):
            if num!='':
                temp.append(int(num)) 
            num=""
        if(i=='}'):
            if num!='':
                temp.append(int(num)) 
            list1[len(temp)]=temp
            maxN=max(len(temp),maxN)
            temp=[]
            num=""
    list1 = list1[1:maxN+1]
    
    if len(list1)==1:
        return list1[0]
    
    answer=list1[0]
    for i in range(0,len(list1)-1):
        answer+=[x for x in list1[i+1] if x not in list1[i]]
    return answer