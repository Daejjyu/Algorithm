N, K = map(int, input().split())
num = list(input())

stack = []
for i in range(N):
    while (K and stack and stack[-1] < num[i]):
        stack.pop()
        K -= 1
    stack.append(num[i])

for i in range(len(stack) - K):
    print(stack[i], end='')
