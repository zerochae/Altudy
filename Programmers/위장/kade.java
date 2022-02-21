package main.level_2;

import java.util.*;

public class 위장 {

    public static int solution(String[][] clothes) {
        int answer = 1;
        Map<String, Set<String>> map = new HashMap<>();

        for(String[] str : clothes) {
            if(map.get(str[1]) == null) {
                Set<String> set = new HashSet<>();
                set.add(str[0]);
                map.put(str[1], set);
            } else {
                map.get(str[1]).add(str[0]);
            }
        }

        if(map.size() == 1) {
            answer = clothes.length;
        } else {
            for(String key : map.keySet()) {
                answer *= map.get(key).size() + 1;
            }
            answer--;
        }
        return answer;
    }

    public static void main(String[] args) {
        solution(new String[][]{{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}}); // 5
//        solution(new String[][]{{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}}); // 3
    }
}
