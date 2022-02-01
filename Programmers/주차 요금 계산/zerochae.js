function solution(fees, records) {

  let answer = [];

  const carList = [];

  class car{
    constructor(number,enter,leave,fee){
      this.number = number;
      this.enter = enter;
      this.leave = leave;
      this.fee = fee;
    }
  }

  // carList 생성

  const set = new Set();

  for(let record of records){
    set.add(record.split(" ")[1]);
  }

  for(let item of set){
    carList.push(new car(item,[],[],0));
  }

  // carList 생성 끝

  // 입출차 시간 기록

  for(let record of records){

    const input = record.split(" ");

    switch(input[2]){
      case "IN": 
      carList.filter(item=>item.number === input[1] ? item.enter.push(input[0]) : null)
      break;
      case "OUT": 
      carList.filter(item=>item.number === input[1] ? item.leave.push(input[0]) : null)
      break;
    }

  }

  // 입출차 시간 기록 끝

  // 요금 계산

  for(let car of carList){

    let totalTime = 0;

    for(let index in car.enter){

      let getIn = car.enter[index];
      let getOut;
      if(car.leave[index] === undefined || car.leave[index] === null) getOut = "23:59";
      else getOut = car.leave[index];

      const time1 = getIn.split(":"); // In
      const time2 = getOut.split(":"); // Out

      totalTime += timeOperate(time1[0],time1[1],time2[0],time2[1]);

    }

    car.fee = feeOperate(totalTime,fees[0],fees[1],fees[2],fees[3]);

  }
  // 요금 계산 끝

  // 넘버 순 정렬 

  carList.sort((a,b)=>{
    return a.number - b.number;
  });

  // 정렬 끝
    
  for(let car of carList){
      answer.push(car.fee);
  }

  return answer
}

// 요금 계산 함수
function feeOperate(totalTime,baseTime,baseRate,unitTime,unitFee){
  if(totalTime <= baseTime) return baseRate;
  else return baseRate + Math.ceil((totalTime-baseTime) / unitTime) * unitFee;
}

// 시간 계산 함수
function timeOperate(inHour,inMin,outHour,outMin){

  let hour = parseInt(outHour) - parseInt(inHour);

  let min = parseInt(outMin) - parseInt(inMin);

  if(min < 0){
    min += 60;
    hour--;
  }

  return (hour * 60) + min;

}