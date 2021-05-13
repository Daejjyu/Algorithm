from collections import defaultdict
def solution(tickets):
    def init_graph():
        routes = defaultdict(list)
        for key, value in tickets:
            routes[key].append(value)
        return routes

    def dfs():
        stack = ["ICN"]
        path = [] 
        while len(stack) > 0:
            top = stack[-1]
            if top not in routes or len(routes[top]) == 0:
                path.append(stack.pop())
            else:
                stack.append(routes[top].pop(0))
        return path[::-1]

    routes = init_graph()
    for r in routes:
        routes[r].sort()

    answer = dfs()
    return answer