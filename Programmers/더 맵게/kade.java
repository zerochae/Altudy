package main.level_2;

import java.util.PriorityQueue;

public class 더맵게 {

    public static int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> queue = new PriorityQueue<>();

        for(int sv : scoville) {
            queue.add(sv);
            if(sv == 0) {
                return -1;
            }
        }

        while(true) {
            long first = queue.remove();
            if(queue.isEmpty() && first < K) {
                return -1;
            }
            if(first >= K) {
                break;
            }
            long second = queue.remove();

            long newSv = first + (second * 2L);

            queue.add((int)newSv);
            answer++;
        }

        return answer;
    }

    public static void main(String[] args) {
//        solution(new int[]{1, 2, 3, 9, 10, 12}, 7); // 2
//        solution(new int[]{7, 7, 3}, 7); // 2
        solution(new int[]{1, 2, 3}, 11); // 2
    }
}
