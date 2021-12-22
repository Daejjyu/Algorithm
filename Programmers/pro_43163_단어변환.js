function solution(begin, target, words) {
  const visited = {}
  const dfs = (word, cnt) => {
    if (word === target) return cnt - 1
    let answer = 0
    visited[word] = 1
    const candidates = words.filter((s) => !visited[s] && [...s].filter((_, i) => s[i] === word[i]).length === begin.length - 1)
    for (let i = 0, l = candidates.length; i < l; i++) {
      const ret = dfs(candidates[i], cnt + 1)
      if (ret) answer = ret
    }
    return answer
  }
  return dfs(begin, 1);
}