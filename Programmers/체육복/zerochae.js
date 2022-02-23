/* get input */
const n = 3;
const lost = [3];
const reserve = [3];
/* get input end*/

/* set param */
class student {
  isHave = true;
  isLost = false;
  isReserve = false;
}

class classRoom {
  studentList = new Array();
  constructor(studentCount) {
    this.studentList = new Array(studentCount).fill(new student());
  }
}
let result = 0;
/* set param end*/

/* solve */
const solution = (n, lost, reserve ) => {

  const myClass = new classRoom(n);

  lost.map((index) => {
    const student = {...myClass.studentList[index - 1]};
    student.isHave = false;
    student.isLost = true;
    return myClass.studentList[index - 1] = {...student}
  });

  reserve.map((index) => {
    const student = {...myClass.studentList[index - 1]};
    student.isReserve = true;
    return myClass.studentList[index - 1] = {...student}
  });

  myClass.studentList.map(student =>{
    if(student.isLost && student.isReserve){
      student.isReserve = false;
      student.isHave = true;
      student.isLost = false;
    }
  })

  myClass.studentList.map((student, index) => {
    if (student.isLost) {
      const prevStudent = myClass.studentList[index - 1];
      const nextStudent = myClass.studentList[index + 1];
      if (prevStudent && prevStudent.isReserve) {
        student.isHave = true;
        prevStudent.isReserve = false;
      } else if (nextStudent && nextStudent.isReserve) {
        student.isHave = true;
        nextStudent.isReserve = false;
      }
    }
  });

  myClass.studentList.map((student) => {
    student.isHave ? result++ : null;
  });
  return result;
};
/* solve end*/

/* print output */
const output = solution(n, lost, reserve);
console.log(output);
/* print output end*/
