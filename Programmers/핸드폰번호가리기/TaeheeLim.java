package com.example.codingtest.level1;

public class 핸드폰번호가리기 {
    public static void main(String[] args) {
        String number1 = "01033334444";

        String number2 = "027778888";

        System.out.println(solution(number1));
    }

    public static String solution(String phone_number){
        String answer = "";
        for(int i = 0; i < phone_number.length() - 4; i++){
            answer += "*";
        }
        answer += phone_number.substring(phone_number.length()-4);

        return answer;
    }
}
