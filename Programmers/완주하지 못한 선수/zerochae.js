const solution = (participant, completion) => {

  const map = new Map();

  for(let person of participant){
    map.has(person) ? map.set(person,map.get(person)+1) : map.set(person,1);
  }

  for(let person of completion){
    map.set(person,map.get(person)-1);
    if(map.get(person) === 0) map.delete(person);
  }

  return map.keys().next().value; 
}