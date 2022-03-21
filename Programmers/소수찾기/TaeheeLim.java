package com.example.codingtest.level2;

import java.util.*;

public class 소수찾기 {
    static TreeSet<String> set = new TreeSet<>();
    static int count = 0;

    public static void main(String[] args) {
        String number1 = "17";
        String number2 = "011";

        System.out.println(solution(number1));
    }



    public static int solution(String numbers) {
        List<Character> arr = new ArrayList<>();
        List<Character> list = new ArrayList<>();

        for (int i = 0; i < numbers.length(); i++) {
            arr.add(numbers.charAt(i));
        }

        for (int i = 0; i < numbers.length(); i++) {
            dfs(arr, list, numbers.length(), i + 1);
        }

        return count;
    }

    //소수 확인
    public static boolean isPrime(int number) {
        int cnt = 0;

        for (int i = 1; i <= number; i++) {
            if(number % i == 0) cnt++;
        }
        if (cnt != 2) {
            return false;
        } else {
            return true;
        }
    }

    //탐색색
    public static void dfs(List<Character> arr, List<Character> list, int n, int r) {
        if(r == 0){
            if(list.get(0) != '0'){
                StringBuilder sb = new StringBuilder();
                for(int i = 0; i < list.size(); i++){
                    sb.append(list.get(i));
                }
                if(!set.contains(sb.toString())){
                    set.add(sb.toString());
                    if(isPrime(Integer.parseInt(sb.toString()))){
                        count++;
                    }
                }
            }
        } else {
            for(int i = 0; i < n; i++){
                list.add(arr.remove(i));
                System.out.println("list : " + list.toString());
                System.out.println("afterRemoveArr : " + arr.toString());
                dfs(arr, list, n - 1, r - 1);
                arr.add(i, list.remove(list.size() - 1));
                System.out.println("arr : " + arr.toString());
            }
        }

    }
}
