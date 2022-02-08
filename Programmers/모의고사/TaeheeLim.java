package com.example.codingtest.level1;

import java.util.*;

public class 모의고사 {
    public static void main(String[] args) {
        int[] answers1 = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
        int[] answers2 = {1,3,2,4,2};

        System.out.println(Arrays.toString(solution(answers1)));
    }
//            1번 : 1, 2, 3, 4, 5,// 1, 2, 3, 4, 5, ... 5개 반복
//            2번 : 2, 1, 2, 3, 2, 4, 2, 5, //2, 1, 2, 3, 2, 4, 2, 5, ... 9개 반복
//            3번 : 3, 3, 1, 1, 2, 2, 4, 4, 5, 5,// 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ... 10개 반복

    public static int[] solution(int[] answers){
        int[] firstLoser = {1, 2, 3, 4, 5};
        int[] secondLoser = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] thirdLoser = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

        List<Integer> firstList = new ArrayList<>();
        List<Integer> secondList = new ArrayList<>();
        List<Integer> thirdList = new ArrayList<>();

        int firstIndex = 0;
        int secondIndex = 0;
        int thirdIndex = 0;

        for(int i = 0; i < answers.length; i++){
            if(firstIndex == firstLoser.length) firstIndex = 0;

            if(secondIndex == secondLoser.length) secondIndex = 0;

            if(thirdIndex == thirdLoser.length) thirdIndex = 0;

            firstList.add(firstLoser[firstIndex]);
            firstIndex++;

            secondList.add(secondLoser[secondIndex]);
            secondIndex++;

            thirdList.add(thirdLoser[thirdIndex]);
            thirdIndex++;
        }
        int[] losers = new int[3];

        int[] answer = {};

        for(int i = 0; i < answers.length; i++){
            if(answers[i] == firstList.get(i)){
                losers[0]++;
            }
            if(answers[i] == secondList.get(i)){
                losers[1]++;
            }
            if(answers[i] == thirdList.get(i)){
                losers[2]++;
            }
        }

        int max = Arrays.stream(losers).max().getAsInt();

        for(int i=0;i<3;i++) {
            if (losers[i] == max) {
                answer = Arrays.copyOf(answer, answer.length + 1);
                answer[answer.length - 1] = i + 1;
            }
        }
        return answer;
    }
}
