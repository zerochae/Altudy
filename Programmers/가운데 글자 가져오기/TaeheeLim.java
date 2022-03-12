package com.example.codingtest.level1;

public class 가운데글자가져오기 {
    public static void main(String[] args) {
        String s1 = "abcde";
        String s2 = "qwer";

        System.out.println(solution(s2));
    }
    //a b c d e f
    //0 1 2 3 4 5

    //a b c d
    //0 1 2 3
    public static String solution(String s){
        String answer = "";

        if(s.length() % 2 ==0){
            int temp = s.length() / 2;
            answer += s.substring(temp - 1, temp + 1);
        } else {
            int temp = s.length() / 2;
            answer += s.charAt(temp);
        }
        return answer;
    }
}
