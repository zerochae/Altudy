void main() {

  print(_solution(12));

}

bool _solution(int num){
  int temp = num.toString().split("").fold<int>(0, (prev, element) => prev + int.parse( element) );
  return num % temp == 0 ? true : false;
}
