package programmers.level1;

import java.util.Arrays;

public class 로또의최저순위와최고순위 {
    public static void main(String[] args) {
        solution(new int[]{44, 1, 0, 0, 31, 25},new int[]{31, 10, 45, 1, 6, 19});
        solution(new int[]{0, 0, 0, 0, 0, 0},new int[]{38, 19, 20, 40, 15, 25});
        solution(new int[]{45, 4, 35, 20, 3, 9},new int[]{20, 9, 3, 45, 4, 35});
    }

    public static int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = {0, 0};
        int zeroCnt = 0;
        Arrays.sort(lottos);
        for(int i = 0; i < 6; i++) {
            if(lottos[i] != 0) break;
            zeroCnt++;
        }
        Arrays.sort(win_nums);
        for(int j = 0; j < 6; j++) {
            for(int k = zeroCnt; k < 6; k++) {
                if(win_nums[j] != lottos[k])    continue;
                answer[0]++;
                answer[1]++;
            }
        }
        answer[0] += zeroCnt;
        for(int i = 0; i < 2; i++) {
            if(answer[i] == 6) answer[i] = 1;
            else if(answer[i] == 5) answer[i] = 2;
            else if(answer[i] == 4) answer[i] = 3;
            else if(answer[i] == 3) answer[i] = 4;
            else if(answer[i] == 2) answer[i] = 5;
            else answer[i] = 6;
        }
        return answer;
    }

}
