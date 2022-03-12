package com.example.codingtest.level1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class 두정수사이의합 {
    public static void main(String[] args) {
        int a1 = 3;
        int a2 = 3;
        int a3 = 5;

        int b1 = 5;
        int b2 = 3;
        int b3 = 3;

        System.out.println(solution(a1, b1));
    }

    public static long solution(int a, int b){
        long answer = 0;
        List<Integer> list = new ArrayList<>();
        list.add(a);
        list.add(b);
        Collections.sort(list);
        for(int i = list.get(0); i <= list.get(1); i++){
            answer += i;
        }
        return answer;
    }
}
