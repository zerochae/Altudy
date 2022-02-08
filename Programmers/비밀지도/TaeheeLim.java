package com.example.codingtest.level1;

import java.util.Arrays;

public class 비밀지도 {
    public static void main(String[] args) {
        int n1 = 5;
        int[] arr1 = {9, 20, 28, 18, 11};
        int[] arr2 = {30, 1, 21, 17, 28};

        int n2 = 6;
        int[] arr12 = {46, 33, 33 ,22, 31, 50};
        int[] arr22 = {27 ,56, 19, 14, 14, 10};

        System.out.println(Arrays.toString(solution(n1, arr1, arr2)));
    }

    public static String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = {};
        answer = new String[n];

        for(int i = 0; i < arr1.length; i++){
            String firstBinaryNumber = Integer.toBinaryString(arr1[i]);
            if(firstBinaryNumber.length() < n){
                int goRound = n - firstBinaryNumber.length();
                for(int j = 0; j < goRound; j++){
                    firstBinaryNumber = "0" + firstBinaryNumber;
                }
            }
            String secondBinaryNumber = Integer.toBinaryString(arr2[i]);
            if(secondBinaryNumber.length() < n){
                int goRound = n - secondBinaryNumber.length();
                for(int j = 0; j < goRound; j++){
                    secondBinaryNumber = "0" + secondBinaryNumber;
                }
            }
            StringBuilder builder = new StringBuilder();
            for(int k = 0; k < n; k++){
                if(firstBinaryNumber.charAt(k) != secondBinaryNumber.charAt(k)){
                    builder.append("#");
                } else if(firstBinaryNumber.charAt(k) == '0'){
                    builder.append(" ");
                } else if(firstBinaryNumber.charAt(k) == '1'){
                    builder.append("#");
                }
            }
            answer[i] = builder.toString();
        }
        return answer;
    }
}
