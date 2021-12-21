function solution(bridge_length, weight, truck_weights) {
  const bridge = Array(bridge_length).fill(0)
  let time = 0;
  let capacity = weight;
  while (truck_weights.length) {
    capacity += bridge.shift()
    if (truck_weights[0] <= capacity) {
      const truckW = truck_weights.shift()
      capacity -= truckW;
      bridge.push(truckW)
    } else {
      bridge.push(0)
    }
    time++;
  }
  return time + bridge_length;
}