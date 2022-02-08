/* get input */
let n = "...!@BaT#*..y.abcdefghijklm.";
/* get input end*/

/* set param */
let result = "";
/* set param end*/

/* solve */
const solution = (n) => {

  n = n.toLowerCase().replace(/([^a-z0-9\.\_\-])/gi,"").replace(/\.+(?=.)/g,"\.").replace(/^\./,"").replace(/\.$/,"").replace(/^$/,"a").match(/.{0,15}/)[0].replace(/\.$/g,"")

  return n.length <= 2 ? solution(n+n.substring(n.length-1)) : n;
};
/* solve end*/

/* print output */
const output = solution(n);
console.log(output);
/* print output end*/
