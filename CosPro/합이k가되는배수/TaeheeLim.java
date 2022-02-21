package com.example.codingtest.cospro.second;

public class 합이k가되는배수 {
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5};
        int K = 3;
        System.out.println(solution(arr, K));
    }

    public static int solution(int[] arr, int K){
        int answer = 0;
        for(int i = 0; i < arr.length; i++){
            for(int j = i + 1; j < arr.length; j++){
                for(int k = j + 1; k < arr.length; k++){
                    if((arr[i] + arr[j] + arr[k]) % 3 == 0) answer++;
                }
            }
        }
        return answer;
    }
}
