package com.example.codingtest.level1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

public class 폰켓몬 {
    public static void main(String[] args) {
        int[] num1 = {3,1,2,3};
        int[] num2 = {3,3,3,2,2,4};
        int[] num3 = {3,3,3,2,2,2};

        System.out.println(solution(num3));
    }

    public static int solution(int[] nums) {
        int limit = nums.length / 2;
        Stack<Integer> pocketBalls = new Stack<>();
        Arrays.sort(nums);

        for (int i = 0; i < nums.length; i++) {
            if(!pocketBalls.isEmpty() && pocketBalls.peek() == nums[i]){
                continue;
            } else {
                pocketBalls.push(nums[i]);
            }
        }
        if(pocketBalls.size() <= limit){
            limit = pocketBalls.size();
        }
        return limit;
    }
}
