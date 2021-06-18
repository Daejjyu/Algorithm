def solution(nums):
    answer = set(nums)
    return min(len(nums)//2,len(answer))