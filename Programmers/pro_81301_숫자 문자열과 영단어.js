// const NUMBER_DICT = {
//   'zero': 0, 'one': 1, 'two': 2, 'three': 3, 'four': 4,
//   'five': 5, 'six': 6, 'seven': 7, 'eight': 8, 'nine': 9
// } //이렇게 하면 오류가 난다 왜일까..
const NUMBER_DICT = {
  'zero': '0', 'one': '1', 'two': '2', 'three': '3', 'four': '4',
  'five': '5', 'six': '6', 'seven': '7', 'eight': '8', 'nine': '9'
}
function solution(s) {
  let answer = '';
  let numStr = ''
  for (let i = 0, l = s.length; i < l; i++) {
    if (s[i] < 'a' || 'z' < s[i]) {
      answer += s[i]
      continue;
    }
    numStr += s[i]
    const dictNum = NUMBER_DICT[numStr]
    if (dictNum) {
      numStr = ''
      answer += dictNum+''
    }
  }
  return parseInt(answer);
}