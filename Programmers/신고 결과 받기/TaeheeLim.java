package com.example.codingtest.level1;

import java.util.*;

public class TaeheeLim {
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

        for (int i = 0; i < id_list.length; i++) {
            memberIndex.put(id_list[i], i);
        }
        for (String single : report) {
            String[] ids = single.split(" ");
            String reportMember = ids[0];
            String beingReportedMember = ids[1];

            if (!map.containsKey(beingReportedMember)) {
                map.put(beingReportedMember, new ArrayList<>());
            }

            List<Integer> list = map.get(beingReportedMember);
            if (!list.contains(memberIndex.get(reportMember))) {
                list.add(memberIndex.get(reportMember));
            }
        }
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
