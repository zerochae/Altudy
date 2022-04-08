/* get input */
const n = "5 3";
// const n = "2 2";
/* get input end */

/* solve */
process.stdin.setEncoding("utf8");
process.stdin.on("data", (data) => {
  const n = data.split(" ");
  const a = Number(n[0]),
    b = Number(n[1]);
  let line = "";

  for (let i = 0; i < b; i++) {
    for (let j = 0; j < a; j++) {
      line += "*";
    }
    line += "\n";
  }
  console.log(line);
});
/* solve end */
