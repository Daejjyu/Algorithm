from collections import deque
def solution(bridge_length, weight, truck_weights):
	bridge = [0]*bridge_length
	que=deque()
	time, idx, cur_weight=0, 0, 0
	while(idx<len(truck_weights)):
		time+=1
		if(time>bridge_length):
			cur_weight-=que.popleft()
		if(cur_weight+truck_weights[idx]<=weight):
			cur_weight+=truck_weights[idx]
			que.append(truck_weights[idx])
			idx+=1
		else:
			que.append(0)        
	return time+bridge_length