package programmers.level2;

import java.util.*;

public class 기능개발 {
    public static void main(String[] args) {
        solution(new int[]{93,35,55},new int[]{1,30,5});
        solution(new int[]{95,90,99,99,80,99},new int[]{1,1,1,1,1,1});
    }

    public static int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        int cnt = 0;
        while(true){
            int innerCnt = 0;
            for(int i=0; i<progresses.length;i++){
                if(progresses[i]>=100){
                    continue;
                }
                progresses[i] += speeds[i];
                while (progresses[cnt]>=100){
                    cnt++;
                    innerCnt++;
                    if(cnt == progresses.length) break;
                }
            }
            if(innerCnt >0){
                answer = Arrays.copyOf(answer, answer.length + 1);
                answer[answer.length-1] = innerCnt;
                if(cnt == progresses.length) break;
            }
        }

        return answer;
    }
}