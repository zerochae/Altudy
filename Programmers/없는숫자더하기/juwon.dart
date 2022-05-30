void main(){
  print(solution(numbers));
}

List<int> numbers = [5,8,4,0,6,7,9];

int solution(List<int> numList){
  return numList.fold<int>(45, (previousValue, element)=>  previousValue -= element);
}