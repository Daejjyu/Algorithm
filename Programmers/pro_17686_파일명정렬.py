def solution(files):
    splitFiles = [['' for _ in range(4)] for _ in range(len(files))]
    for num in range(len(files)):
        file = files[num]
        file = file.upper()
        i=0
        while(i<len(file) and file[i].isdigit()==False):
            splitFiles[num][0]+=file[i]
            i+=1
        while(i<len(file) and len(splitFiles[num][1])<5 and file[i].isdigit()):
            splitFiles[num][1]+=file[i]
            i+=1
        splitFiles[num][2]=file[i:]
        splitFiles[num][3]=num    
    return [files[x[3]] for x in sorted(splitFiles,key = lambda x:(x[0],int(x[1])))]