package com.example.codingtest.level1;

public class 삼진법뒤집기 {

    public static void main(String[] args) {
        int number1 = 45;
        int number2 = 125;

        System.out.println(solution(number1));
    }

    public static int solution(int n) {
        String answer = "";

        while(n > 0){
            answer += (n % 3);
            n /= 3;
        }
        System.out.println(answer);
        return Integer.parseInt(answer, 3);
    }
}
