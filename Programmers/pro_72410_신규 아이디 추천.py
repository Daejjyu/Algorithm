def solution(new_id):
    #rule1. 3자 이상 15자 이하
    #rule2. -, _, . 만 사용 가능
    #rule3. 마침표는 처음과 끝에 사용 x, 연속적으로도 x
    
    #1.
    new_id=new_id.lower()
    #2.
    accept_char = ['-','_','.']
    temp=''
    for i in new_id:
        if('0'<=i and i<='9' or 'a'<=i and i<='z' or i in accept_char):
            temp +=i            
    new_id = temp
    #3
    temp=''
    for i in range(len(new_id)):
        if(i>0 and new_id[i-1]=='.' and new_id[i]=='.'):
            continue
        temp+=new_id[i]
    new_id = temp
    #4,5
    if(new_id[0]=='.'):
        if(len(new_id)>=2):
            new_id = new_id[1:]
        else:
            new_id = 'a'    
    if(len(new_id)>=1 and new_id[-1]=='.'):
        if(len(new_id)>=2):
            new_id=new_id[:-1]
        else:
            new_id = 'a'
    #6. 
    if(len(new_id)>=16):
        new_id = new_id[:15]
        if(new_id[-1]=='.'):
            new_id = new_id[:-1]
    #7.
    while(len(new_id)<=2):
        new_id+=new_id[-1]
    return new_id