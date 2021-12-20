const DAYS = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']
const DATE_PER_MONTH = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

function solution(a, b) {
  return DAYS[(Array(a - 1).fill(0).reduce((acc, _, i) => acc += DATE_PER_MONTH[i], 0) + b + 4) % 7];
}