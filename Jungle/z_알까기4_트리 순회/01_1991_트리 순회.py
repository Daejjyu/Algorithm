import sys

def solve():
input = sys.stdin.readline

Tree ={}
N = int(input())

for _ in range(N):
    list1 = list(input().split())
    Tree[list1[0]]={(list1[1],list1[2])}


def preorder(char):
    list1 = list(list(Tree.get(char))[0])
    print(char,end='')
    if(list1[0]!='.'):
        preorder(list1[0])
    if (list1[1] != '.'):
        preorder(list1[1])

def inorder(char):
    list1 = list(list(Tree.get(char))[0])
    if(list1[0]!='.'):
        inorder(list1[0])
    print(char, end='')
    if (list1[1] != '.'):
        inorder(list1[1])

def postorder(char):
    list1 = list(list(Tree.get(char))[0])
    if(list1[0]!='.'):
        postorder(list1[0])
    if (list1[1] != '.'):
        postorder(list1[1])
    print(char,end='')

preorder('A')
print()
inorder('A')
print()
postorder('A')