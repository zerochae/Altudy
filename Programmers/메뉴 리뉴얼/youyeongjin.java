package programmers.level2;

import java.util.*;

public class 메뉴리뉴얼 {

    public static void main(String[] args) {
        //solution(new String[]{"ABCFG"},new int[]{2,3,4});
        //solution(new String[]{"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"},new int[]{2,3,4});
        //solution(new String[]{"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"},new int[]{2,3,5});
        solution(new String[]{"XYZ", "XWY", "WXA"},new int[]{2,3,4});
    }

    public static String[] solution(String[] orders, int[] course) {
        String[] answer = {};

        for(int i=0;i<course.length;i++){
            Map<String,Integer> map = new HashMap<>();

            for(int j=0;j<orders.length;j++){
                if(orders[j].length() < course[i]) continue;

                char[] chars = orders[j].toCharArray();
                Arrays.sort(chars);
                combination(map,chars,0,course[i],"");

            }
            List<Map.Entry<String, Integer>> list = new ArrayList<>(map.entrySet());
            list.sort(Map.Entry.comparingByValue());
            int max = list.get(list.size()-1).getValue();
            if(max < 1) break;
            answer = Arrays.copyOf(answer,answer.length+1);
            answer[answer.length-1] = list.get(list.size()-1).getKey();

            for(int j=list.size()-2;j>0;j--){
                if(list.get(j).getValue() != max) break;
                answer = Arrays.copyOf(answer,answer.length+1);
                answer[answer.length-1] = list.get(j).getKey();
            }
        }

        Arrays.sort(answer);

        return answer;
    }

    public static void combination(Map<String,Integer> map,char[] order,int start,int r,String result){
        if(r==0){
            if(map.containsKey(result)){
                map.put(result,map.get(result)+1);
            }else{
                map.put(result,0);
            }
            return;
        }else{
            for(int i=start;i<order.length;i++){
                combination(map,order,i+1,r-1,result+order[i]);
            }
        }
    }


}
