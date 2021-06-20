function solution(skill, skill_trees) {
    const len = skill_trees.length
    var answer = 0;
    for (let i = 0; i < len; i++) {
        let filter_skill = [...skill_trees[i]].filter((v) => skill.indexOf(v) != -1).join("")
        if (skill.slice(0, filter_skill.length) === filter_skill)
            answer += 1
    }
    return answer;
}