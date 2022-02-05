const solution = (participant, completion) => {

  const map = new Map();

  for(let person of participant){
    map.has(person) ? map.set(person,map.get(person)+1) : map.set(person,1);
  }

  for(let person of completion){
    map.get(person) === 1 ? map.delete(person) : map.set(person,map.get(person)-1);
  }

  return map.keys().next().value; 
}