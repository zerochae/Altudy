void main(){
  print(_solution(participant, completion));
}

final participant = ["mislav", "stanko", "mislav", "ana"];

final completion = ["stanko", "ana", "mislav"];

String _solution(List<String> par, List<String> com){
  par.sort();
  com.sort();

  for(int i = 0; i < com.length; i++){
    if(par[i] != com[i]){
      return par[i];
    }
  }

  return par[par.length - 1];
}