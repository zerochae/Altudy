package com.example.codingtest.level1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class 예산 {
    public static void main(String[] args) {
        int[] d1 = {1, 3, 2, 5, 4};
        int budget1 = 9;

        int[] d2 = {2, 2, 3, 3};
        int budget2 = 10;

        System.out.println(solution(d1, budget1));
    }

    public static int solution(int[] d, int budget){
        int sum = 0;
        int count = 0;

        Arrays.sort(d);
//        1,2,3,4,5
        for(int number : d){
            sum += number;
            if(sum <= budget){
                count++;
            } else {
                break;
            }
        }
        return count;
    }
}
