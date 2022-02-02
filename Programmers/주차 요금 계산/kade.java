package main.level_2;

import java.util.*;

public class 주차요금계산 {

    public static int[] solution(int[] fees, String[] records) {

        Map<String, List<String>> map = new HashMap<>();
        Map<String, Integer> result = new HashMap<>();

        for(String rec : records) {
            String[] s = rec.split(" ");

            if(rec.contains("IN")) {
                List<String> list = new ArrayList<>();
                list.add(s[0]);
                map.put(s[1], list);
            } else {
                List<String> timeWrap = map.get(s[1]);
                String[] inTime = timeWrap.get(0).split(":");
                String[] outTime = s[0].split(":");
                int totalTime = 0;

                totalTime = Integer.parseInt(outTime[1]) - Integer.parseInt(inTime[1]);

                if(Integer.parseInt(outTime[0]) - Integer.parseInt(inTime[0]) > 0) {
                    totalTime += (Integer.parseInt(outTime[0]) - Integer.parseInt(inTime[0])) * 60;
                }
                if(result.get(s[1]) != null) {
                    Integer temp = result.get(s[1]);
                    result.put(s[1], totalTime + temp);
                } else {
                    result.put(s[1], totalTime);
                }
                map.remove(s[1]);
            }
        }
        System.out.println(map);
        if(map.size() > 0) {
            Set<String> keys = map.keySet();
            for(String key : keys) {
                String[] inTime = map.get(key).get(0).split(":");
                int totalTime = 0;

                totalTime = 59 - Integer.parseInt(inTime[1]);

                if(23 - Integer.parseInt(inTime[0]) > 0) {
                    totalTime += (23 - Integer.parseInt(inTime[0])) * 60;
                }
                if(result.get(key) != null) {
                    Integer temp = result.get(key);
                    result.put(key, totalTime + temp);
                } else {
                    result.put(key, totalTime);
                }
            }
        }

        for(String key : result.keySet()) {
            Integer totalFee = result.get(key);

            if(totalFee <= fees[0]) {
                result.put(key, fees[1]);
            } else {
                int i = (totalFee - fees[0]) % fees[2] == 0
                        ? (totalFee - fees[0]) / fees[2] : (totalFee - fees[0]) / fees[2] + 1;
                int total = (i * fees[3]) + fees[1];
                result.put(key, total);
            }
        }

        List<Map.Entry<String, Integer>> entries = new LinkedList<>(result.entrySet());
        Collections.sort(entries, (o1, o2) -> o1.getKey().compareTo(o2.getKey()));

        int[] answer = new int[entries.size()];
        for(int i = 0; i < entries.size(); i++) {
            answer[i] = entries.get(i).getValue();
        }
        return answer;
    }

    public static void main(String[] args) {
        solution(new int[]{1, 0, 1, 1},
                new String[]{"05:34 5961 IN",
                             "06:00 0000 IN",
//                             "06:34 0000 OUT",
//                             "07:59 5961 OUT",
//                             "07:59 0148 IN",
//                             "18:59 0000 IN",
//                             "19:09 0148 OUT",
//                             "22:59 5961 IN",
                             "23:00 1010 IN"}); // 14600, 34400, 5000
//
//        solution(new int[]{120, 0, 60, 591},
//                new String[]{"16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN"}); // 0, 591

//        solution(new int[]{1, 461, 1, 10}, new String[]{"00:00 1234 IN"}); // 14841
    }
}
