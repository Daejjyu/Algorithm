
function solution(n, computers) {
  const visited = Array(n).fill(0)
  let answer = 0;
  const dfs = (idx) => {
    visited[idx] = 1;
    computers[idx].forEach((v, i) => {
      if (v === 1 && visited[i] === 0)
        dfs(i)
    })
  }

  for (let i = 0, l = visited.length; i < l; i++) {
    if (!visited[i]) {
      dfs(i)
      answer++;
    }
  }
  return answer;
}