package com.example.codingtest.level1;

public class 다트게임 {
    public static void main(String[] args) {
        String dartResult1 = "1D2S#10S";
        String dartResult2 = "1D2S0T";
        String dartResult3 = "1S*2T*3S";

        System.out.println(solution(dartResult1));
    }
    public static int solution(String dartResult) {
        int[] tries = new int[3];
        char[] result = dartResult.toCharArray();
        int idx = -1;

        for (int i = 0; i < result.length; i++) {
            if (result[i] >= '0' && result[i] <= '9') {
                idx++;
                tries[idx] += Integer.parseInt(String.valueOf(result[i]));
                if (i + 1 != result.length - 1 && result[i + 1] == '0'&& result[i] == '1') {
                    tries[idx] -= Integer.parseInt(String.valueOf(result[i]));
                    tries[idx] = 10;
                    i++;
                }
            } else if (result[i] == 'D') {
                tries[idx] *= tries[idx];
            } else if(result[i] == 'T') {
                tries[idx] *= tries[idx] * tries[idx];
            } else if (result[i] == '*') {
                if (idx > 0) tries[idx - 1] *= 2;
                tries[idx] *= 2;
            } else if (result[i] == '#') {
                tries[idx] *= -1;
            }
        }
        return tries[0] + tries[1] + tries[2];
    }
}
