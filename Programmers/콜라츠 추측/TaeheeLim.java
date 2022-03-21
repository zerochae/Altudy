package com.example.codingtest.level1;

public class 콜라츠추측 {
    static int index = 0;

    public static void main(String[] args) {
        int num1 = 6;
        int num2 = 16;
        int num3 = 626331;

        System.out.println(solution(num3));
    }

    public static int solution(long number) {
        long result;
        if(number != 1){
            index++;
            if (number % 2 == 0) {
                result = Long.valueOf(number) / 2;
                solution(result);
            } else if(number % 2 != 0){
                result = (Long.valueOf(number) * 3) + 1;
                solution(result);
            }
        }
        if (index >= 500) {
            return -1;
        }
        return index;
    }
}
