package com.example.codingtest.level1;

public class 문자열내p와y의개수 {
    public static void main(String[] args) {
        String s = "pPoooyY";

        String s2 = "Pyy";

        System.out.println(solution(s));
    }

    public static boolean solution(String s){
        String lowerString = "";

        for(int i = 0; i < s.length(); i++){
            lowerString += Character.toLowerCase(s.charAt(i));
        }

        int pCount = 0;
        int yCount = 0;

        for(int i = 0; i < lowerString.length(); i++){
            if(lowerString.charAt(i) == 'p') pCount++;
            if(lowerString.charAt(i) == 'y') yCount++;
        }

        if(pCount == yCount){
            return true;
        } else {
            return false;
        }
    }
}
