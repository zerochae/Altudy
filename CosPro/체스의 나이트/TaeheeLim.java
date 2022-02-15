package com.example.codingtest.cospro;

import java.util.ArrayList;
import java.util.List;

public class 체스의나이트 {
    public static void main(String[] args) {
        String data1 = "A7";
        String data2 = "A5";
        String data3 = "D4";
        String data4 = "A1";
        String data5 = "H1";
        String data6 = "H8";

        System.out.println(solution(data1));
    }

    public static int solution(String pos) {
        int answer = 0;
        int[][] chess = new int[8][8];
        List<Integer> num = getNum(pos);

        int[] i = {-2, -1, 1, 2, 2, 1, -1, -2};
        int[] j = {1, 2, 2, 1, -1, -2, -2, -1};

        for(int k = 0; k < chess.length; k++){
            int possibleX = i[k] + num.get(0);
            int possibleY = j[k] + num.get(1);
//            System.out.println(possibleX);
//            System.out.println(possibleY);
//            System.out.println();
            if ((possibleY >=0 && possibleX >= 0) && (possibleX <=7 && possibleY <= 7)) answer++;
        }


        return answer;
    }

    public static List<Integer> getNum(String pos){
        String[] split = pos.split("");
        List<Integer> list = new ArrayList<>();

        if(split[0].equals("A")) list.add(0);
        if(split[0].equals("B")) list.add(1);
        if(split[0].equals("C")) list.add(2);
        if(split[0].equals("D")) list.add(3);
        if(split[0].equals("E")) list.add(4);
        if(split[0].equals("F")) list.add(5);
        if(split[0].equals("G")) list.add(6);
        if(split[0].equals("H")) list.add(7);

        list.add(Integer.parseInt(split[1]) - 1);

        return list;
    }


}
