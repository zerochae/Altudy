package com.example.codingtest.level1;

public class 부족한금액계산하기 {
    public static void main(String[] args) {
        int price = 3;
        int money = 20;
        int count = 4;

        System.out.println(solution(price, money, count));
    }
    //3 * 2
    //3 * 3
    //3 * 4
    public static long solution(int price, int money, int count) {
        long answer = 0;

        for (long i = 1; i <= count; i++) {
            answer += (long) price * i;
        }
        if(answer - money <=0){
            return 0;
        }
        return answer - money;
    }
}
