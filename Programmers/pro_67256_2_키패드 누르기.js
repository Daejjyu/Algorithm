const getCoord = (idx) => {
  return [(idx - 1) % 3, ((idx - 1) / 3) | 0]
}

const getDist = (nextIdx, curIdx) => {
  const [nC, nR] = getCoord(nextIdx)
  const [c, r] = getCoord(curIdx)
  return Math.abs(nC - c) + Math.abs(nR - r)
}

const DICT_HAND = { 'left': 'L', 'right': 'R' }
const updateHand = (nextIdx, hand, handIdx, answer) => {
  hand === 'left' ? handIdx[0] = nextIdx : handIdx[1] = nextIdx
  return answer + DICT_HAND[hand]
}

function solution(numbers, hand) {
  var answer = '';
  const handIdx = [10, 12];
  const LEFT_NUMS = [1, 4, 7]
  const RIGHT_NUMS = [3, 6, 9]
  numbers.forEach(num => {
    if (LEFT_NUMS.includes(num)) answer = updateHand(num, 'left', handIdx, answer)
    else if (RIGHT_NUMS.includes(num)) answer = updateHand(num, 'right', handIdx, answer)
    else {
      if (num === 0) num = 11;
      const [leftDist, rightDist] = [getDist(num, handIdx[0]), getDist(num, handIdx[1])]
      if (leftDist === rightDist) {
        answer = hand === 'left' ?
          updateHand(num, 'left', handIdx, answer) : updateHand(num, 'right', handIdx, answer);
      } else if (leftDist < rightDist) {
        answer = updateHand(num, 'left', handIdx, answer)
      } else {
        answer = updateHand(num, 'right', handIdx, answer)
      }
    }
  })
  return answer;
}