package com.example.codingtest.level1;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class 문자열과영단어 {
    public static void main(String[] args) {
        String data1 = "one4seveneight";
        String data2 = "23four5six7";
        String data3 = "2three45sixseven";
        String data4 = "123";

        System.out.println(solution(data4));
    }

    public static int solution(String s){
        String initial = "";
        String finalAnswer = "";
        Map<String, Integer> keyAndValue = getKeyAndValue();

        for(int i = 0; i < s.length(); i++){
            initial += s.charAt(i);
            if(Character.isDigit(s.charAt(i))){
                finalAnswer += s.charAt(i);
                initial = "";
            } else {
                if(keyAndValue.containsKey(initial)){
                    finalAnswer += keyAndValue.get(initial);
                    initial = "";
                }
            }
        }

        return Integer.parseInt(finalAnswer);
    }

    public static Map<String, Integer> getKeyAndValue(){
        Map<String, Integer> map = new HashMap<>();
        map.put("zero", 0);
        map.put("one", 1);
        map.put("two", 2);
        map.put("three", 3);
        map.put("four", 4);
        map.put("five", 5);
        map.put("six", 6);
        map.put("seven", 7);
        map.put("eight", 8);
        map.put("nine", 9);
        map.put("ten", 10);

        return map;
    }
}
