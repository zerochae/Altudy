package com.example.codingtest.level2;

import java.util.*;

public class TaeheeLim {

    public static void main(String[] args) {
        int[] fees = {180, 5000, 10, 600};
        String[] records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT"
                , "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN"
                , "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};

        int[] fees2 = {1, 461, 1, 10};
        String[] records2 = {"00:00 1234 IN", "00:00 2222 IN", "00:00 3333 IN", "00:00 4444 IN"};

        solution(fees, records);
    }

    //fees는 기본시간, 기본요금, 초과(분), 추가요금
    //주차된 누적 시간을 구해야함
    //IN하고 OUT 출차 시간이 없다면 23:59로 지정
    //10으로 나눈 값이 딱 떨어지지 않을경우는 Math.ceil로 반올림
    //차량번호가 작은 순서대로 요금을 배열에 담아서 return

    //0000, 0148, 5961
    public static int[] solution(int[] fees, String[] records) {

        Map<String, Car> map = new HashMap<>();

        for (String record : records) {
            String[] single = record.split(" ");
            //차가 들어온 경우
            if (single[2].equals("IN")) {
                //한번 들어왔다가 나간적이 있는 경우
                if (map.containsKey(single[1])) {
                    Car car = map.get(single[1]);
                    //해당 차량 객체에 fee를 초기화해줌(나간시간 - 들어간시간)... 그러면 총 주차시간이 나옴
                    car.getFinalFees();
                    car.setParkingTIme(single[0]);
                    car.setLeaveTime("23:59");
                    continue;
                }
                //특정 차량이 한번만 IN한 경우 or 처음 IN한 경우
                map.put(single[1], new Car(single[0]));
            } else {
                //OUT한 경우 leaveTime set해줌
                map.get(single[1]).setLeaveTime(single[0]);
            }
        }

        int[] answer = {};
        //map에 담겨있는 key값을 set으로 가져와서 string 배열에 재할당
        String[] keys = map.keySet().toArray(new String[0]);

        //차량번호 순으로 정렬
        Arrays.sort(keys);

        //차량 번호를 하나씩 가지고와서 요금계산
        for (String key : keys) {
            answer = Arrays.copyOf(answer, answer.length + 1);
            //Car class의 getFinalFees 메소드를 다시 한번 실행시켜서 주차된 시간을 계산해서 총 주차시간을 매개변수로 넘겨줌
            answer[answer.length - 1] = getSingleFee(fees, map.get(key).getFinalFees());
        }
        return answer;
    }

    public static int getSingleFee(int[] fees, int time){
        if(fees[0] > time){
            //주차된 시간 보다 기본 시간이 더 크다면 기본요금 반환
            return fees[1];
        } else {
            //기본 시간이 초과되었다면 문제에서 주어진 공식대로 처리
            return fees[1] + (int)Math.ceil((double)(time - fees[0])/fees[2]) * fees[3];
        }
    }
}

class Car{
    String parkingTIme;
    String leaveTime;
    int fee;

    Car(String inTime){
        this.parkingTIme = inTime;
        this.leaveTime = "23:59";
        this.fee = 0;
    }

    public void setParkingTIme(String parkingTIme) {
        this.parkingTIme = parkingTIme;
    }

    public void setLeaveTime(String leaveTime) {
        this.leaveTime = leaveTime;
    }

    public int getFinalFees(){
        String[] parkingTimes = this.parkingTIme.split(":");
        String[] leavingTimes = this.leaveTime.split(":");
        int parkingTimesInMinutes = Integer.parseInt(parkingTimes[0]) * 60 + Integer.parseInt(parkingTimes[1]);
        int leavingTimesInMinutes = Integer.parseInt(leavingTimes[0]) * 60 + Integer.parseInt(leavingTimes[1]);
        this.fee += leavingTimesInMinutes - parkingTimesInMinutes;
        return this.fee;
    }

    @Override
    public String toString() {
        return "Car{" +
                ", parkingTIme='" + parkingTIme + '\'' +
                ", leaveTime='" + leaveTime + '\'' +
                ", fee=" + fee +
                '}';
    }
}
