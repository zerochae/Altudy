public class 언제까지오르막길이야 {

  public static int solution(int[] arr) {
    int start = 0;
    List<Integer> list = new ArrayList<>();
    while(start < arr.length) {
      int speed = 1;
      int nowPosition = arr[start];
      for(int i = start + 1; i < arr.length; i++) {
        if(arr[i] > nowPosition) {
          nowPosition = arr[i];
          speed++;
        } else {
          break;
        }
      }
      list.add(speed);
      start++;
    }
    int answer = 0;
    for(int i = 0; i < list.size(); i++) {
      if(answer < list.get(i)) {
        answer = list.get(i);
      }
    }
    
    return answer;
  }

  public static void main(String[] args) {
    solution(new int[]{3, 1, 2, 4, 5, 1, 2, 2, 3, 4});
  }
}