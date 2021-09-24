from collections import defaultdict
def solution(table, languages, preference):
    answer = []
    maxScore = 0
    prefDict = defaultdict(int)
    for lang,pref in zip(languages,preference):
        prefDict[lang] = pref
    for content in table:
        langScores = content.split(' ')
        l = len(langScores)
        result = 0
        for i in range(1,l):
            result += prefDict[langScores[i]]*(l-i)
        if result > maxScore:
            answer = [langScores[0]]
            maxScore = result
        elif result == maxScore:
            answer.append(langScores[0])
            maxScore = result
    return sorted(answer)[0]