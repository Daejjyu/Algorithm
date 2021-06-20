def solution(cacheSize, cities):
    cache = [] # [city,cnt]
    answer = 0
    for city in cities:
        city = city.upper()
        isCached=False
        for i in range(len(cache)): #hit
            if(cache[i][0]==city):
                cache[i][1]=0
                answer+=1
                isCached=True
                break            
        if(isCached == False): #miss
            answer+=5
            if(len(cache)<cacheSize):
                cache.append([city,0])
            elif(cacheSize>0):
                max_val = [0,0]
                for i in range(len(cache)):
                    if(max_val[1]<cache[i][1]):
                        max_val = [i,cache[i][1]]
                cache[max_val[0]]=[city,0]
        for i in range(len(cache)):                
            cache[i][1]+=1     
    return answer
