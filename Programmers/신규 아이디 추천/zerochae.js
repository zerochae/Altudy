/* get input */
let n = "...!@BaT#*..y.abcdefghijklm.";
/* get input end*/

/* set param */
let result = "";
/* set param end*/

/* solve */
const solution = (n) => {

  n = n.toLowerCase(). // 1단계
  replace(/([^a-z0-9\.\_\-])/g,""). // 2단계
  replace(/\.+(?=.)/g,"\."). // 3단계
  replace(/^\./,"").replace(/\.$/,""). // 4단계
  replace(/^$/,"a"). //5 단계 replace(/^$/,"a") === padEnd(1,'a');
  match(/.{0,15}/)[0].replace(/\.$/g,"") // 6단계 match(/.{0,15}/)[0] === slice(0,15)
  
  return n.length <= 2 ? solution(n+n.substring(n.length-1)) : n; // 7단계
};
/* solve end*/

/* print output */
const output = solution(n);
console.log(output);
/* print output end*/
