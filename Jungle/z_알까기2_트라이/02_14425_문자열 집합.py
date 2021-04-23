import sys
input = sys.stdin.readline

class Node(object):
    def __init__(self,key,data=None):
        self.key = key
        self.data = data
        self.children = {}

class Trie(object):
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):
        curr_node = self.head

        for char in string:
            if char not in curr_node.children:
                curr_node.children[char] = Node(char)
            curr_node = curr_node.children[char]

        curr_node.data=string

    def search(self,string):
        curr_node = self.head

        for char in string:
            if char in curr_node.children:
                curr_node = curr_node.children[char]
            else:
                return False

        if curr_node.data != None:
            return True

n,m = map(int,input().split())

word_trie = Trie()
word_len = [False]*501 #Max Len

for _ in range(n):
    word = input().strip()
    word_trie.insert(word)
    word_len[len(word)]=True
cnt =0
for _ in range(m):
    word = input().strip()
    if word_len[len(word)] and word_trie.search(word):
        cnt+=1
print(cnt)