void main(){
  print(_solution(n));
}

final n = 12345;

List<String> _solution(int num){
  List<String> temp = [];
  temp = num.toString().split("");
  temp.sort( (a, b) => b.compareTo(a));
  return temp;
}

