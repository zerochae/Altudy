package com.example.codingtest.level1;

import java.util.Arrays;

public class 정수제곱근판별 {
    public static void main(String[] args) {
        long n1 = 121;
        long n2 = 3;

        System.out.println(solution(n1));
    }

    public static long solution(long n){
        double sqrt = Math.sqrt(n);
        String temp = sqrt + "";
        String[] split = temp.split("\\.");

        if(split[1].length() > 1){
            return -1;
        } else {
            return (long) Math.pow(sqrt + 1, 2);
        }
    }
}
