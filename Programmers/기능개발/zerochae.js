function solution(progresses, speeds) {
    
  speeds = speeds.reverse();

  const answer = [];
  const queue = [];

  for(let item of progresses){
    queue.unshift(item);
  }

  while(queue.length !== 0){

    let count = 0;

    for(let index in queue){
      queue[index] += speeds[index];
    }

    while(queue[queue.length-1] >= 100){
      queue.pop();
      count++;
    }
    if(count !== 0) answer.push(count);
  }
  return answer;
}