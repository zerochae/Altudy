package com.example.codingtest.level1;

import java.util.ArrayList;
import java.util.List;

public class 나머지가1이되는수찾기 {
    public static void main(String[] args) {
        int n1 = 10;
        int n2 = 12;

        System.out.println(solution(n1));
    }
    public static int solution(int n){
        List<Integer> list = new ArrayList<>();

        for (int i = 1; i  <= n; i++) {
            if(n % i == 1) list.add(i);
        }

        return list.get(0);
    }
}
