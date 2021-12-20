from itertools import combinations
import math

def isPrime(num):    
    for i in range(2, int(math.sqrt(num))+1):
        if num%i==0: 
            return 0
    return 1
    
def solution(nums):    
    return sum([isPrime(sum(x)) for x in combinations(nums,3)])