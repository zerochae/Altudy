package com.example.codingtest.level1;

import java.util.Arrays;

public class 없는숫자더하기 {

    public static void main(String[] args) {
        int[] data1 = {1,2,3,4,6,7,8,0};
        int[] data2 = {5,8,4,0,6,7,9};

        System.out.println(solution(data1));
        System.out.println(solution2(data1));
    }

    public static int solution(int[] numbers){
        int answer = 45;
        for(int number : numbers){
            answer -= number;
        }
        return answer;
    }

    public static int solution2(int[] numbers){
        int answer = 0;
        int[] sum = {0,1,2,3,4,5,6,7,8,9};

        for(int i = 0; i< sum.length; i++){
            for(int j=0; j< numbers.length; j++){
                if(sum[i] == numbers[j]){
                    sum[i] -= numbers[j];
                }
            }
            answer += sum[i];
        }
        return answer;
    }
}
