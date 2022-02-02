package com.example.codingtest.level2;

import java.util.*;

public class 주차요금계산 {

    public static void main(String[] args) {
        int[] fees = {180, 5000, 10, 600};
        String[] records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT"
                          , "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN"
                          , "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};

        int[] fees2 = {1, 461, 1, 10};
        String[] records2 = {"00:00 1234 IN"};

        solution(fees, records);
    }

    //fees는 기본시간, 기본요금, 초과(분), 추가요금
    //주차된 누적 시간을 구해야함
    //IN하고 OUT 출차 시간이 없다면 23:59로 지정
    //10으로 나눈 값이 딱 떨어지지 않을경우는 Math.ceil로 반올림
    //차량번호가 작은 순서대로 요금을 배열에 담아서 return

    //0000, 0148, 5961
    public static int[] solution(int[] fees, String[] records) {
        int[] answer = {};

        List<String> temporalList = new ArrayList<>();

        for(int i = 0; i < records.length; i++){
            String str = "";
            String[] split = records[i].split(" ");
            String temp = split[0];
            split[0] = split[1];
            split[1] = temp;
            str = split[0] + " " + split[1] + " " + split[2];
            temporalList.add(str);
        }
        String[] newRecords = temporalList.toArray(new String[temporalList.size()]);
        Arrays.sort(newRecords);
        System.out.println(Arrays.toString(newRecords));
        Map<String, Integer> map = new HashMap<>();

        int count = 0;

        for(int i = 0; i < newRecords.length; i++){
            if(i == newRecords.length - 1){
                map.put(newRecords[i].substring(0, 4), count + 1);
                count = 0;
                break;
            }
            if(newRecords[i].substring(0, 4).equals(newRecords[i + 1].substring(0, 4))){
                count++;
            } else {
                map.put(newRecords[i].substring(0, 4), count + 1);
                count = 0;
            }
        }
        System.out.println(map.toString());
        System.out.println(Arrays.toString(fees));
        int[] newAnswer = new int[map.size()];
        for(int i = 0; i < newRecords.length; i++){
            if(newRecords.length == 1){
                String beginHour = newRecords[i].substring(5, 7);
                String beginMinute = newRecords[i].substring(8, 10);
                int resultHour = (23 - Integer.parseInt(beginHour)) * 60;
                int resultMinute = 59 - Integer.parseInt(beginMinute);
                int sum = resultHour + resultMinute;
                int result = fees[1] + ((int)(Math.ceil(sum - fees[0] / fees[2])) * fees[3]);
                newAnswer[i] = result;
            }
        }

        return newAnswer;
    }

}
