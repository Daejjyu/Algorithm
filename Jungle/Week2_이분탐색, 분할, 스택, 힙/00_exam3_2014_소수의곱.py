# import heapq
#
# K, N = map(int, input().split())
# prime = list(map(int, input().split()))
# ans = 0
# key = {}
# que = []
# for i in prime:
#     que.append(i)
#
# maxValue = 0
# while (N):
#     top = que[0]
#     heapq.heappop(que)
#     for i in prime:
#         next = top * i
#         if (len(que) > N and next > maxValue):
#             continue
#         if (key.get(i * top) is None):
#             heapq.heappush(que, next)
#             maxValue = max(maxValue, next)
#             key[i * top] = 1
#     N -= 1
#
# print(prime)
# print(que)
# print(que[-1])
