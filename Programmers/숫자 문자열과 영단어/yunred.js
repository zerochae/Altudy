function solution(s) {
  let arr = [
    'zero',
    'one',
    'two',
    'three',
    'four',
    'five',
    'six',
    'seven',
    'eight',
    'nine',
  ];
  var answer = 0;
  let arrItem;
  for (let i = 0; i < arr.length; i++) {
    arrItem = arr[i];
    let item = new RegExp(arrItem, 'g');
    s = s.replace(item, i);
  }
  return (answer = Number(s));
}

console.log(solution('one4seveneight'));
