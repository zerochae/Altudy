import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class youyeongjin {
    public static void main(String[] args) {
        solution(new int[]{180, 5000, 10, 600},new String[]{"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"});
        solution(new int[]{120, 0, 60, 591},new String[]{"16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN"});
        solution(new int[]{1, 461, 1, 10},new String[]{"00:00 1234 IN"});
    }

    public static int[] solution(int[] fees, String[] records) {
        Map<String,Car> map = new HashMap<String,Car>();
        for(String record : records){
            String[] data = record.split(" ");
            if(data[2].equals("IN")){
                if(map.containsKey(data[1])){
                    Car car = map.get(data[1]);
                    car.getTime();
                    car.setInTime(data[0]);
                    car.setOutTime("23:59");
                    continue;
                }
                map.put(data[1],new Car(data[0]));
            }else{
                map.get(data[1]).setOutTime(data[0]);
            }
        }

        Object[] mapkey = map.keySet().toArray();
        Arrays.sort(mapkey);
        int[] answer = {};
        for(Object key : mapkey){
            answer = Arrays.copyOf(answer,answer.length+1);
            answer[answer.length-1] = getFee(fees,map.get((String)key).getTime());
        }
        return answer;
    }

    public static int getFee(int[] fees,int time){
        if(time <= fees[0]){
            return fees[1];
        }else{
            return fees[1] + (int)Math.ceil((double)(time - fees[0])/fees[2]) * fees[3];
        }
    }

    public static class Car {
        String inTime;
        String outTime;
        int fee;

        Car(String inTime){
            this.inTime = inTime;
            this.outTime = "23:59";
            this.fee = 0;
        }

        public void setInTime(String inTime) {
            this.inTime = inTime;
        }

        public void setOutTime(String outTime) {
            this.outTime = outTime;
        }

        public int getTime() {
            String[] inTimes = this.inTime.split(":");
            String[] outTimes = this.outTime.split(":");

            int inTimeMinutes = Integer.parseInt(inTimes[0])*60 + Integer.parseInt(inTimes[1]);
            int outTimeMinutes = Integer.parseInt(outTimes[0])*60 + Integer.parseInt(outTimes[1]);
            this.fee += outTimeMinutes-inTimeMinutes;
            return this.fee;
        }
        @Override
        public String toString() {
            return "Car{" +
                    "inTime='" + inTime + '\'' +
                    ", outTime='" + outTime + '\'' +
                    '}';
        }
    }
}
