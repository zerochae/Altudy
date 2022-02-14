package com.example.codingtest.level1;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class 로또최고순위최저순위 {
    public static void main(String[] args) {
        int[] lottos1 = {44, 1, 0, 0, 31, 25};
        int[] lottos2 = {0, 0, 0, 0, 0, 0};
        int[] lottos3 = {45, 4, 35, 20, 3, 9};

        int[] win_nums1 = {31, 10, 45, 1, 6, 19};
        int[] win_nums2 = {38, 19, 20, 40, 15, 25};
        int[] win_nums3 = {20, 9, 3, 45, 4, 35};

        System.out.println(Arrays.toString(solution(lottos3, win_nums3)));
    }


    public static int[] solution(int[] lottos, int[] win_nums){
        int[] answer = {};
        int missedNumber = 0;
        int successShot = 0;

        for(int number : lottos){
            if(number == 0) missedNumber++;
        }

        for(int myNumber : lottos){
            for(int winNumber : win_nums){
                if(myNumber == winNumber) successShot++;
            }
        }
        answer = Arrays.copyOf(answer, answer.length + 1);
        answer[answer.length - 1] = lottoRank(missedNumber + successShot);

        answer = Arrays.copyOf(answer, answer.length + 1);
        answer[answer.length - 1] = lottoRank(successShot);

        return answer;
    }

    public static int lottoRank(int number){
        Map<Integer, Integer> map = new HashMap<>();
        map.put(6,1);
        map.put(5,2);
        map.put(4,3);
        map.put(3,4);
        map.put(2,5);
        map.put(1,6);
        map.put(0,6);

        return map.get(number);
    }
}
