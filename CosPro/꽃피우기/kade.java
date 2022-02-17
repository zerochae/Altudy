// 다음과 같이 import를 사용할 수 있습니다.
import java.util.*;

class Solution {
    public int solution(int[][] garden) {
        int answer = 0;
        while(true) {
            List<int[]> list = new ArrayList<>();
            for(int i = 0; i < garden.length; i++) {
                for(int j = 0; j < garden[i].length; j++) {
                    if(garden[i][j] == -1) {
                        garden[i][j] = 1;
                        list.add(new int[]{i, j});
                    } else if(garden[i][j] == 1) {
                        list.add(new int[]{i, j});
                    }
                }
            }
            if(list.size() == garden.length * garden[0].length) {
                break;
            }
            for(int[] position : list) {
                int i = position[0];
                int j = position[1];
                // u
                if(i - 1 >= 0) garden[i - 1][j] = -1;
                // d
                if(i + 1 < garden.length) garden[i + 1][j] = -1;
                // l
                if(j - 1 >= 0) garden[i][j - 1] = -1;
                // r
                if(j + 1 < garden[i].length) garden[i][j + 1] = -1;
            }
            answer++;
        }
        
        return answer;
    }
    
    // 아래는 테스트케이스 출력을 해보기 위한 main 메소드입니다.
    public static void main(String[] args) {
        Solution sol = new Solution();
        // int[][] garden1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
        int[][] garden1 = {{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}};
        int ret1 = sol.solution(garden1);
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret1 + " 입니다.");
        
        int[][] garden2 = {{1, 1}, {1, 1}};
        int ret2 = sol.solution(garden2);
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret2 + " 입니다.");
        
    }    
}