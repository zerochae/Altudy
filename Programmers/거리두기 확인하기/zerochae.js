/* get input */
const n = [
  ["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"],
  ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"],
  ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"],
  ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"],
  ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"],
];
/* get input end*/

/* solve */
const solution = (rooms) => {

  return rooms.map((room) => // room[0] room[1] ... room[4]
    room.some((row, ri) => // "POOOP" ... "POXXP"
      row.split("").some((col, ci, arr) => { // "P" "O" "O" "O" "P" ... "X" "X" "P"
        return col === "X" ? false : search(room, arr, ri, ci, col); })
  ) ? 0 : 1 );
};

const search = (room, arr, ri, ci, col) => {

  const count = [ 

    (room[ri - 1] !== undefined ? room[ri - 1].charAt(ci) : null), // up undefined ?
    (room[ri + 1] !== undefined ? room[ri + 1].charAt(ci) : null), // down undefined ?
    arr[ci - 1], // left
    arr[ci + 1] // right 
  ].filter( (el) => el === "P").length; // P count > 0 , O count < 1 

  return (col === "P" && count > 0) || (col === "O" && count > 1);
};
/* solve end*/

/* print output */
const output = solution(n);
console.log(output);
/* print output end*/
