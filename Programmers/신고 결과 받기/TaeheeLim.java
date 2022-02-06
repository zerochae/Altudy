package com.example.codingtest.level1;

import java.util.*;

public class 신고결과 {
    public static void main(String[] args) {
        String[] idList = {"muzi", "frodo", "apeach", "neo"};
        String[] report = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
        int k = 2;

        String[] idList2 = {"con", "ryan"};
        String[] report2 = {"ryan con", "ryan con", "ryan con", "ryan con"};
        int k2 = 3;

        System.out.println(solution(idList, report, k));
    }

    public static int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        Map<String, Integer> memberIndex = new HashMap<>();
        Map<String, List<Integer>> map = new HashMap<>();

        //index라는 map에다가 캐릭터이름을 key값으로 그리고 value로 id_list배열의 index를 저장
        for (int i = 0; i < id_list.length; i++) {
            memberIndex.put(id_list[i], i);
        }
        for (String single : report) {
            String[] ids = single.split(" ");
            String reportMember = ids[0]; // muzi   apeach frodo muzi apeach
            String beingReportedMember = ids[1]; //   frodo  frodo  neo   neo  muzi

            //최초 신고시에 toId를 key로 갖는 ArrayList생성...
            if (!map.containsKey(beingReportedMember)) {
                map.put(beingReportedMember, new ArrayList<>());
            }

            //toId의 값을 갖고 있는 map안의 ArrayList를 가지고 와서 새로운 list에 주입
            List<Integer> list = map.get(beingReportedMember);
            //중복확인
            if (!list.contains(memberIndex.get(reportMember))) {
                list.add(memberIndex.get(reportMember));
            }
        }// for 끝
        System.out.println(map.toString());
        for (int i = 0; i < id_list.length; i++) {
            String id = id_list[i];
            if (map.containsKey(id) && map.get(id).size() >= k) {
                for (int num : map.get(id)) {
                    answer[num]++;
                }
            }
        }
        System.out.println(Arrays.toString(answer));
        return answer;
    }
}
