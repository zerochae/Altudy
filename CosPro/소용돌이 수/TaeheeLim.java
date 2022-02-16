package com.example.codingtest.cospro;

import java.util.Arrays;

public class 소용돌이수 {
    public static void main(String[] args) {
        int data1 = 3;
        int data2 = 2;
        System.out.println(solution(data1));
    }

    public static int solution(int n){
        int answer = 0;
        int[][] arr = new int[n][n];
        int number = 1;

        int x = 0;
        int y = 0;
        char direction = 'r';

        for(int i = 0; i < n * n; i++){
            arr[x][y] = number++;

            switch (direction){
                case 'r':
                    if(y + 1 < n && arr[x][y+1] == 0){
                        y++;
                    } else {
                        direction = 'd';
                        x++;
                    }
                    break;
                case 'l':
                    if(y - 1 >= 0 && arr[x][y-1] == 0){
                        y--;
                    } else {
                        direction = 'u';
                        x--;
                    }
                    break;
                case 'u':
                    if(x - 1 >= 0 && arr[x-1][y] == 0){
                        x--;
                    } else {
                        direction = 'r';
                        y++;
                    }
                    break;
                case 'd':
                    if(x + 1 < n && arr[x+1][y] ==0){
                        x++;
                    } else {
                        direction = 'l';
                        y--;
                    }
                    break;
            }

        }
        for(int i = 0; i < n; i++){
            answer += arr[i][i];
        }

        return answer;
    }
}
