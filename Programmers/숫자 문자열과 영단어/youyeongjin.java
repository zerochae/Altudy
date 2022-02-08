package programmers.level1;

import java.util.HashMap;
import java.util.Map;

public class 숫자문자열과영단어 {
    public static void main(String[] args) {
        solution("one4seveneight");
        solution("23four5six7");
        solution("2three45sixseven");
        solution("123");
    }

    public static int solution(String s) {
        StringBuilder sb = new StringBuilder();
        Map<String,Integer> map = new HashMap<>();
        map.put("zero", 0);
        map.put("one", 1);
        map.put("two", 2);
        map.put("three", 3);
        map.put("four", 4);
        map.put("five", 5);
        map.put("six", 6);
        map.put("seven", 7);
        map.put("eight", 8);
        map.put("nine", 9);
        char[] chars = s.toCharArray();
        String numberString = "";
        for(char item : chars){
            if(item >= '0' && item <= '9'){
                sb.append(item);
            }else{
                numberString += item;
                if(map.get(numberString)!=null){
                    sb.append(map.get(numberString));
                    numberString = "";
                }
            }
        }
        return Integer.parseInt(sb.toString());
    }
}
