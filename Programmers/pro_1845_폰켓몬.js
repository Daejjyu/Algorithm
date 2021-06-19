function solution(nums) {
    return Math.min(parseInt(nums.length / 2), new Set(nums).size)
}
