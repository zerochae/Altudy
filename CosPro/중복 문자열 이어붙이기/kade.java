// 다음과 같이 import를 사용할 수 있습니다.
import java.util.*;

class Main {
    public int solution(String s1, String s2) {
        int answer = 0;
				String s1Str = s1;
				String s2Str = s2;
				
				for(int i = 1, j = 2; i < s2.length(); i++, j++) {
					if(s1.substring(s1.length() - j, s1.length() - 1).equals(s2.substring(0, i))) {
						s1Str += s2.substring(i + 1, s2.length());
						break;
					}
				}
			
				for(int i = 1, j = 2; i < s1.length(); i++, j++) {
					if(s2.substring(s2.length() - j, s2.length() - 1).equals(s1.substring(0, i))) {
						s2Str += s1.substring(i + 1, s1.length());
						break;
					}
				}
        return Math.min(s1Str.length(), s2Str.length());
    }
    
    public static void main(String[] args) {
      Main sol = new Main();
      String s1 = new String("ababc");
      String s2 = new String("abcdab");
      int ret = sol.solution(s1, s2);
      
      // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
      System.out.println("solution 메소드의 반환 값은 " + ret + " 입니다.");
  }