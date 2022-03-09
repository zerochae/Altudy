package programmers;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class 메뉴리뉴얼 {
    public static void main(String[] args) {
        String [] orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
        int [] course = {2, 3, 4};

        List<String> res = solution(orders, course);

        Collections.sort(res);

        for (String re : res) {
            System.out.println(re);
        }
    }
    public static List<String> solution(String[] orders, int[] course) {
        List<String> answer = new ArrayList<>();

        for(int i = 0; i < course.length; i++){
            Map<String, Integer> map = new HashMap<>();
            for(int j = 0 ; j < orders.length; j++){
                map = combineCourse(orders[j], "", course[i], 0, 0, map);
            }
            int max = -1;

            for (String s : map.keySet()) {
                max = Math.max(map.get(s), max);
            }

            for (String s : map.keySet()) {
                if (map.get(s) >= 2){
                    if(max == map.get(s)){
                        answer.add(s);
                    }
                }
            }
        }

        return answer;
    }

    public static Map<String, Integer> combineCourse(String order, String res, int max, int level, int start, Map<String, Integer> map){
//        // orders 문자열 안되있을 경우 정렬
//        for(int i = 0; i < orders.length; i++) {
//            char[] temp = orders[i].toCharArray();
//            Arrays.sort(temp);
//            orders[i] = String.valueOf(temp);
//            System.out.println(orders[i]);
//        }
        if(level == max){
            char [] charArr = res.toCharArray();

            Arrays.sort(charArr);

            res = String.valueOf(charArr);

            // res의 값이 존재하면 값을 반환 없으면 기본값(0) 반환
            map.put(res, map.getOrDefault(res, 0) + 1);
        }else{
            for(int i = start; i < order.length(); i++){
                combineCourse(order, res+String.valueOf(order.charAt(i)), max, level + 1, i + 1, map);
            }
        }
        return map;
    }
}
