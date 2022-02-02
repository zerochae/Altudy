const progresses = [93, 30, 55];

const speeds = [1,30,5];

solution(progresses,speeds);

function solution(progresses, speeds) {

  const answer = [];
  speeds = speeds.reverse();
  progresses = progresses.reverse();

  class Stack {
    constructor() {
      this.arr = [];
      this.length = 0;
    }
    push(item) {
      this.arr[this.length++] = item;
    }
    pop() {
      return this.length > 0 ? this.arr[--this.length] : null;
    }
    isEmpty() {
      return this.length === 0
    }
    top() {
      return this.arr[this.length - 1];
    }
  }

  const stack = new Stack();

  for(let item of progresses){
    stack.push(item);
  }

  while(!stack.isEmpty()){

    let count = 0;

    for(let index in stack.arr){
      stack.arr[index] += speeds[index];
    }

    while(stack.top() >= 100){
      stack.pop();
      count++;
    }
    if(count !== 0) answer.push(count);
  }

  console.log(answer);

  return answer;
}