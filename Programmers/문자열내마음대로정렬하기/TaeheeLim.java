package com.example.codingtest.level1;

import java.util.*;

public class 문자열내마음대로정렬하기 {

    public static void main(String[] args) {
        String[] strings1 = {"sun", "bed", "car"};
        String[] strings2 = {"abce", "abcd", "cdx"};
        int n1  = 1;
        int n2  = 2;

        System.out.println(Arrays.toString(solution(strings2, n2)));
    }

    public static String[] solution(String[] strings, int n){
        String[] answer = {};
        List<String> list = new ArrayList<>();

        for(int i = 0; i < strings.length; i++){
            list.add(strings[i].charAt(n) + strings[i]);
        }
        Collections.sort(list);

        for(String temporalValue : list){
            answer = Arrays.copyOf(answer, answer.length + 1);
            answer[answer.length - 1] = temporalValue.substring(1);
        }
        return answer;
    }
}
