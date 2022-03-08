package com.example.codingtest.level1;

public class 약수의개수와덧셈 {
    public static void main(String[] args) {
        int left1 = 13;
        int left2 = 24;

        int right1 = 17;
        int right2 = 27;

        System.out.println(solution(left1,right1));
    }

    public static int solution(int left, int right) {
        int answer = 0;

        for (int i = left; i <= right; i++) {
            int count = getNumbers(i);

            if(count % 2 == 0){
                answer += i;
            } else {
                answer -= i;
            }
        }
        return answer;
    }

    public static int getNumbers(int number){
        int check = 0;
        for (int i = 1; i <= number; i++) {
            if(number % i == 0) check++;
        }
        return check;
    }
}
