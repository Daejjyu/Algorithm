import sys
input=sys.stdin.readline

class Node(object):
    def __init__(self, key, data=None):
        self.key = key
        self.data = data
        self.child = {}

class Trie(object):
    def __init__(self):
        self.head = Node(None)

    def insert(self,word):
        curr_node = self.head
        for char in word:
            if char not in curr_node.child:
                curr_node.child[char]=Node(char)
            elif curr_node.child[char].data:
                return 1
            curr_node = curr_node.child[char]
        curr_node.data = word

        return 0


for _ in range(int(input())):
    T = Trie()
    nums = list(list(input().strip()) for _ in range(int(input())))

    nums.sort(key = lambda x: len(x))
    for i in nums:
        if (T.insert(i)):
            print("NO")
            break
    else:
        print("YES")