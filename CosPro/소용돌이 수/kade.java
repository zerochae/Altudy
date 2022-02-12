package main.cos_pro;

import java.util.Arrays;

public class 소용돌이수 {

    public int solution(int n) {
        int answer = 0;
        int[][] arr = new int[n][n];
        int row = -1;
        int col = 0;
        int sw = 1;
        int index = 1;

        while(true) {
            for(int a = 0; a < n; a++) {
                row += sw;
                arr[col][row] = index++;
            }
            n--;
            if(n > 0) {
                for(int a = 0; a < n; a++) {
                    col += sw;
                    arr[col][row] = index++;
                }
                sw = sw * -1;
            } else {
                break;
            }
        }

        for(int i = 0; i < arr.length; i++) {
            answer += arr[i][i];
        }

        return answer;
    }

    public static void main(String[] args) {
        소용돌이수 sol = new 소용돌이수();
        int n1 = 3;
        int ret1 = sol.solution(n1);
        System.out.println("solution 메소드의 반환 값은 " + ret1 + " 입니다.");

        int n2 = 2;
        int ret2 = sol.solution(n2);
        System.out.println("solution 메소드의 반환 값은 " + ret2 + " 입니다.");
    }
}
