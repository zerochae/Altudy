package com.example.codingtest.level2;

import java.util.*;

public class 메뉴리뉴얼 {
    public static void main(String[] args) throws Exception {
        Solution solution = new Solution();
//        System.out.println(Arrays.toString(solution.solution(new String[] {"XYZ", "XWY", "WXA"}, new int[] {2, 3, 4})));
        System.out.println(Arrays.toString(solution.solution(new String[] {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"}, new int[] {2, 3, 5})));
    }

    public static class Solution {
        private Map<String, Integer> menu = new HashMap<>();

        public String[] solution(String[] orders, int[] course) {

            List<String> answer = new ArrayList<>();
            for(int i = 0; i < course.length; i++){
                for(int j = 0; j < orders.length; j++){
                    //index j 번째 배열마다 String 길이로 visited 확인, default 로 전부 false
                    boolean[] check = new boolean[orders[j].length()];
                    String[] sort_order = orders[j].split("");
                    //중복을 제거하기 위해 sort해서 정렬
                    Arrays.sort(sort_order);
                    dfs(sort_order, check, 0, course[i]);
                }

                List<Map.Entry<String, Integer>> entries = new ArrayList<>(menu.entrySet());
                //Map Value 값을 내림차순으로 정렬
                entries.sort((entry1, entry2) -> entry2.getValue().compareTo(entry1.getValue()));

                int max = 0;
                for(Map.Entry<String, Integer> entry : entries) {
                    //메뉴가 2명의 손님으로부터 2번 이상 주분 되어야함
                    if(entry.getValue() > 1 && max <= entry.getValue()) {
                        max = entry.getValue();
                        answer.add(entry.getKey());
                    }
                }
                menu.clear();
            }

            String[] arr = answer.toArray(new String[1]);
            Arrays.sort(arr);

            return arr;
        }

        //int r = 세트 메뉴 단품 개수
        public void dfs(String[] arr, boolean[] check, int index, int r) {
            if (r == 0) {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < arr.length; i++) {
                    if (check[i]){
                        sb.append(arr[i]);
                    }
                }

                if(menu.containsKey(sb.toString())){
                    menu.put(sb.toString(), menu.get(sb.toString()) + 1);
                } else{
                    menu.put(sb.toString(), 1);
                }
            } else {
                //index = 0, r = 2, arr.length = 5, arr = "ABCDE"
                //index = 1, r = 1, arr.length = 5, arr = "ABCDE"
                for (int i = index; i < arr.length; i++) {
                    check[i] = true;
                    dfs(arr, check, i + 1, r - 1);
                    check[i] = false;
                }
            }
        }
    }
}
