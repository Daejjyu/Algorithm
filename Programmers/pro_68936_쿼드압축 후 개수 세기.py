    
def solution(arr):
    answer = []
    def quad(r,c,size):
        pivot = arr[r][c]
        for i in range(r,r+size):
            for j in range(c, c+size):
                if(arr[i][j]!=pivot):
                    half = size//2
                    quad(r,c,half)
                    quad(r+half,c,half)
                    quad(r,c+half,half)
                    quad(r+half,c+half,half)
                    return
        answer.append(pivot)            
    quad(0,0,len(arr))            
    return [answer.count(0),answer.count(1)]