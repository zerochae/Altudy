package com.example.codingtest.level1;

public class 소수만들기 {
    public static void main(String[] args) {
        int[] numbers1 = {1,2,3,4};
        int[] numbers2 = {1,2,7,6,4};

        System.out.println(solution(numbers2));
    }

    public static int solution(int[] nums){
        int answer = 0;

        for(int i = 0; i < nums.length; i++){
            for(int j = i + 1; j < nums.length; j++){
                for(int k = j + 1; k < nums.length; k++){
                    int number = nums[i] + nums[j] + nums[k];
                    if(check(number)){
                        answer++;
                    }
                }
            }
        }
        return answer;
    }

    public static boolean check(int number){
        boolean check = true;

        for(int i = 2; i < number; i++){
            if(number % i == 0 ){
                check = false;
                break;
            }
        }
        return check;
    }
}
