package main.level_2;

import java.util.*;

public class 프린터 {

    public static int solution(int[] priorities, int location) {
        int answer = 0;
        char en = 'A';
        List<Node> list = new ArrayList<>();
        for(int item : priorities) {
            list.add(new Node(item, en++ + ""));
        }

        int start = 0;
        while(start < list.size()) {
            Node temp = new Node(Integer.MIN_VALUE, "");
            int index = 0;
            for(int i = start; i < list.size(); i++) {
                if(list.get(i).value > temp.value) {
                    temp = list.get(i);
                    index = i;
                }
            }
            List<Node> head = list.subList(start, index);
            List<Node> tail = list.subList(index, list.size());
            List<Node> tempArr = list.subList(0, start);
            list = new ArrayList<>(tempArr);
            list.addAll(tail);
            list.addAll(head);
            start++;
        }

        for(Node node : list) {
            answer++;
            if(node.key.equals((char)('A' + location) + "")) {
                break;
            }
        }

        return answer;
    }

    static class Node {
        int value;
        String key;

        public Node(int value, String key) {
            this.value = value;
            this.key = key;
        }

        @Override
        public String toString() {
            return  value + key;
        }
    }

    public static void main(String[] args) {
        solution(new int[]{2, 1, 3, 2}, 2); // 1
//        solution(new int[]{1, 1, 9, 1, 1, 1}, 0);// 5

    }
}
