from collections import defaultdict
def solution(record):
    name_dict = defaultdict(str)
    
    #change name
    for i in record:
        if(i[0]=='E' or i[0]=='C'):
            cmd = i.split(' ')
            name_dict[cmd[1]] = cmd[2]
    
    answer = []
    for i in record:
        cmd = i.split(' ')
        if(cmd[0]=='Enter'):
            answer.append(name_dict[cmd[1]]+"님이 들어왔습니다.")
        elif(cmd[0]=='Leave'):
            answer.append(name_dict[cmd[1]]+"님이 나갔습니다.")
        elif(cmd[0]=='Change'):
            continue    
    return answer


