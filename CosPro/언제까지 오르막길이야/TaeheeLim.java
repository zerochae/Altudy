package com.example.codingtest.cospro.second;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class 언제까지오르막길이야 {
    public static void main(String[] args) {
        int[] arr = {3, 1, 2, 4, 5, 1, 2, 2, 3, 4};
        System.out.println(solution(arr));
    }

    public static int solution(int[] arr){
        int answer = 0;
        int index = 1;
        int previousNumber = arr[0];
        //int[] arr = {3, 1, 2, 4, 5, 1, 2, 2, 3, 4};

        for(int i = 1; i < arr.length; i++){
            if(arr[i] > previousNumber) index++;
            else {
                answer = Math.max(answer, index);
                index = 1;
            }
            previousNumber = arr[i];
        }

        return answer;
    }
}
