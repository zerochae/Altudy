package programmers.level2;

import java.util.Collections;
import java.util.PriorityQueue;

public class 프린터 {
    public static void main(String[] args) {
        solution(new int[]{2,1,3,2},2);
        solution(new int[]{1,1,9,1,1,1},0);
    }

    public static int solution(int[] priorities, int location) {
        int answer = 0;
        PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());

        for(int n : priorities){
            queue.offer(n);
        }

        while(!queue.isEmpty()){
            for(int i = 0;i<priorities.length;i++){
                if(queue.peek() == priorities[i] ){
                    queue.poll();
                    answer++;
                    if(location == i ) return answer;
                }
            }
        }

        return answer;
    }
}
