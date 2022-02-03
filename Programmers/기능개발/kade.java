package main.level_2;

import java.util.*;

public class 기능개발 {

    public static int[] solution(int[] progresses, int[] speeds) {
        Map<Integer, Integer> map = new HashMap<>();

        for(int i = 0; i < progresses.length; i++) {
            int day = 0;
            int percent = progresses[i];
            while(percent < 100) {
                percent += speeds[i];
                day++;
            }
            map.put(i, day);
        }

        Map<Integer, Integer> result = new HashMap<>();
        int temp = map.get(0);
        result.put(0, 1);
        int index = 0;
        for(int i = 1; i < map.size(); i++) {
            if(temp >= map.get(i)) {
                result.put(index, result.get(index) + 1);
            } else {
                result.put(++index, 1);
                temp = map.get(i);
            }
        }
        int[] answer = new int[result.size()];

        for(int i = 0; i < result.size(); i++) {
            answer[i] = result.get(i);
        }
        return answer;
    }

    public static void main(String[] args) {
//        solution(new int[]{93, 30, 55}, new int[]{1, 30, 5}); // 2, 1
//        solution(new int[]{95, 90, 99, 99, 80, 99}, new int[]{1, 1, 1, 1, 1, 1}); // 1, 3, 2
//        solution(new int[]{99, 1, 99, 1}, new int[]{1, 1, 1, 1}); // 1, 3
        solution(new int[]{20, 99, 93, 30, 55, 10}, new int[]{5, 10, 1, 1, 30, 5}); // 3, 3
    }
}
