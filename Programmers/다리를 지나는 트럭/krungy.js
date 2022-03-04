/* get input */
const bridge_length = 2;
const weight = 10;
const truck_weights = [7, 4, 5, 6]; // output = 8
// ---
// const bridge_length = 100;
// const weight = 100;
// const truck_weights = [10]; // output = 101
// ---
// const bridge_length = 100;
// const weight = 100;
// const truck_weights = [10, 10, 10, 10, 10, 10, 10, 10, 10, 10]; // output = 110
/* get input end */

/* solve */
function solution(bridge_length, weight, truck_weights) {
  var answer = 0;
  let time = 0;
  let initialTruckNumber = truck_weights.length;
  let queue = Array.from({ length: bridge_length }, () => 0);
  let weightInBridge = 0;
  let passedTruckCount = 0;

  while (initialTruckNumber >= passedTruckCount) {
    time++;
    let currentTruck = truck_weights[0];
    let leftBridge = queue.shift();
    weightInBridge -= leftBridge;
    if (leftBridge !== 0) passedTruckCount++;
    if (currentTruck === undefined) {
      continue;
    }
    if (weightInBridge + currentTruck > weight) queue.push(0);
    else {
      queue.push(currentTruck);
      truck_weights.shift();
      weightInBridge += currentTruck;
    }
  }

  return (answer = time - 1);
}
/* solve end */

/* print output */
const output = solution(bridge_length, weight, truck_weights);
console.log(output);
/* print output end */
