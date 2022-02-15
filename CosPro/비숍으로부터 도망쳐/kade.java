// 다음과 같이 import를 사용할 수 있습니다.
import java.util.*;

class Main {
    public int solution(String[] bishops) {
        // 여기에 코드를 작성해주세요.
        int answer = 64;
				Set<String> set = new HashSet<>();
				int[] posisions = new int[]{1, 2, 3, 4, 5, 6, 7, 8};
			
				for(String item : bishops) {
					for(int i = 0; i < 4; i++) {
						int row = Integer.parseInt(item.charAt(1) + "");
						int col = posisions[(int)item.charAt(0) % 65];
						while(true) {
							switch(i) {
								case 0: row--; col--; break;
								case 1: row--; col++; break;
								case 2: row++; col--; break;
								case 3: row++; col++; break;
							}
							if(
								(row >= 1 && col >= 1) &&
								(row <= 8 && col <= 8)
							) {
								set.add(row + "" + col);
							} else {
								break;
							}
						}
					}
				}
        return answer - set.size() - 1;
    }
 public static void main(String[] args) {
        Main sol = new Main();
        String[] bishops1 = {new String("D5")};
        int ret1 = sol.solution(bishops1);
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret1 + " 입니다.");

        String[] bishops2 = {new String("D5"), new String("E8"), new String("G2")};
        int ret2 = sol.solution(bishops2);
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret2 + " 입니다.");
    }
}
