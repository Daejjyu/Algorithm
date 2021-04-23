import sys

trie = {"word": 0}
total = 0
while True:
    try:
        word = sys.stdin.readline().strip()
        1/len(word)
        temp = trie
        for c in word:
            if c not in temp.keys():
                temp[c] = {"word": 0}
            temp = temp[c]
        temp["word"] += 1
        total += 1

    except:
        def dfs(now_dict, now, word):
            word += now
            if now_dict["word"] > 0:
                print("%s %.4f" % (word, (now_dict["word"] / total) * 100))
            for next in sorted(now_dict.keys()):
                if next != "word":
                    dfs(now_dict[next], next, word)
        dfs(trie, "", "")
        break