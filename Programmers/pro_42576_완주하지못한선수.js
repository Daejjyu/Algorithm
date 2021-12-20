function solution(participant, completion) {
    const participantDict = {}
    participant.forEach(name => participantDict[name] ? participantDict[name] += 1 : participantDict[name] = 1)
    completion.forEach(name => participantDict[name] -= 1)
    return Object.entries(participantDict).find(([_, value]) => value > 0)[0]
}