/* get input */
const bridge_length = 100;
const weight = 100;
const truck_weights = [10];
/* get input end */

/* solve */
const solution = (bridge_length, weight, truck_weights) => {
  let bridge = [];
  let time = 1;
  const crossed_truck = [];
  const totalLength = truck_weights.length;

  while (crossed_truck.length !== totalLength) {
    const truck_weight = truck_weights.shift();

    const totalWeight = bridge.reduce((acc, truck) => {
      return (acc += truck.weight);
    }, 0);

    truck_weight + totalWeight <= weight
      ? bridge.push({
          weight: truck_weight,
          time: 0,
        })
      : truck_weights.unshift(truck_weight);

    time++;

    bridge.map((truck) => {
      return truck.time++;
    });

    bridge = bridge.filter((truck) => {
      if (truck.time === bridge_length) crossed_truck.push(truck);
      return truck.time !== bridge_length;
    });
  }

  return time;
};
/* solve end */

/* print output */
const output = solution(bridge_length, weight, truck_weights);
console.log(output);
/* print output end */
