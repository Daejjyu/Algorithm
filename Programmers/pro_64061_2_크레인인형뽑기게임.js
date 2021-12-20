const getDoll = (board, idx) => {
  const boardSize = board.length;
  for (let i = 0; i < boardSize; i++) {
    const dollIdx = board[i][idx]
    if (dollIdx) {
      board[i][idx] = 0
      return dollIdx
    }
  }
  return 0;
}

function solution(board, moves) {
  let answer = 0;
  const bucket = []
  moves.forEach((idx) => {
    const dollIdx = getDoll(board, idx - 1)
    if (dollIdx) {
      if (bucket.length && bucket[bucket.length - 1] === dollIdx) {
        bucket.pop()
        answer += 2
      }
      else bucket.push(dollIdx)
    }
  })
  return answer;
}