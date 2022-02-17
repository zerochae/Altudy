package com.example.codingtest.level1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class 두개뽑아서더하기 {
    public static void main(String[] args) {
        int[] numbers1 = {2,1,3,4,1};
        int[] numbers2 = {5,0,2,7};
        int[] numbers3 = {0,100,1000,10};
        System.out.println(Arrays.toString(solution(numbers3)));
    }

    //답 2, 3, 4, 5, 6, 7
    //답 2, 5, 7, 9, 12
    public static int[] solution(int[] numbers) {
        int[] answer = {};
        Arrays.sort(numbers);
        List<Integer> list = new ArrayList<>();

        for(int i = 0; i < numbers.length; i++){
            if(i == numbers.length -1) break;
            for(int j = 1; j < numbers.length; j++){
                if(i == j) continue;
                int addedResult = numbers[i] + numbers[j];
                if(!list.contains(addedResult)) list.add(addedResult);
            }
        }
        for(int i = 0; i < list.size(); i++){
            answer = Arrays.copyOf(answer, answer.length + 1);
            answer[answer.length - 1] = list.get(i);
        }
        Arrays.sort(answer);
        return answer;
    }
}
