package com.example.codingtest.level1;

public class 키패드누르기 {
    public static void main(String[] args) {
        int[] numbers1 = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
        int[] numbers2 = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
        int[] numbers3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

        String hand1 = "right";
        String hand2 = "left";
        String hand3 = "right";

        System.out.println(solution(numbers2, hand2));
    }

    public static String solution(int[] numbers, String hand){
        Person person = new Person("10", "12", hand);
        StringBuilder builder = new StringBuilder();

        for(int number : numbers){
            if(number == 0) number = 11;

            switch (number){
                case 1: case 4: case 7:
                    builder.append("L");
                    person.leftPosition = number + "";
                    break;
                case 3: case 6: case 9:
                    builder.append("R");
                    person.rightPosition = number + "";
                    break;
                case 2: case 5: case 8: case 11:
                    calculateDistance(builder, person, number);
                    break;
            }
        }
        return builder.toString();
    }

    public static void calculateDistance(StringBuilder builder, Person person, int num){
        int substituteLeft = Math.abs(num - Integer.parseInt(person.leftPosition));
        int substituteRight = Math.abs(num - Integer.parseInt(person.rightPosition));
        int leftDistance = (substituteLeft % 3) + (substituteLeft / 3);
        int rightDistance = (substituteRight % 3) + (substituteRight / 3);

        if(leftDistance > rightDistance){
            builder.append("R");
            person.rightPosition = num + "";
        } else if (leftDistance < rightDistance) {
            builder.append("L");
            person.leftPosition = num + "";
        } else if(person.hand.equals("right")) {
            builder.append("R");
            person.rightPosition = num + "";
        } else {
            builder.append("L");
            person.leftPosition = num + "";
        }
    }

    static class Person{
        String leftPosition;
        String rightPosition;
        String hand;

        Person(String left, String right, String hand){
            this.leftPosition = left;
            this.rightPosition = right;
            this.hand = hand;
        }
    }
}




//    public static String solution(int[] numbers, String hand) {
//        StringBuilder answer = new StringBuilder();
//        int[] right = {1,1};
//        int[] left = {3,1};
//        Map<Integer,int[]> pattern = new HashMap();
//        pattern.put(1,new int[]{1,4});
//        pattern.put(2,new int[]{2,4});
//        pattern.put(3,new int[]{3,4});
//        pattern.put(4,new int[]{1,3});
//        pattern.put(5,new int[]{2,3});
//        pattern.put(6,new int[]{3,3});
//        pattern.put(7,new int[]{1,2});
//        pattern.put(8,new int[]{2,2});
//        pattern.put(9,new int[]{3,2});
//        pattern.put(0,new int[]{2,1});
//
//        for(int number : numbers){
//            if(number == 1 || number == 4 || number == 7){
//                left = pattern.get(number);
//                answer.append("L");
//            }else if(number == 3 || number == 6 || number == 9){
//                right = pattern.get(number);
//                answer.append("R");
//            }else{
//                int leftWidth = Math.abs(left[0]-pattern.get(number)[0]) + Math.abs(left[1]-pattern.get(number)[1]);
//                int rightWidth = Math.abs(right[0]-pattern.get(number)[0]) + Math.abs(right[1]-pattern.get(number)[1]);
//                if(leftWidth > rightWidth){
//                    right = pattern.get(number);
//                    answer.append("R");
//                }else if(leftWidth < rightWidth){
//                    left = pattern.get(number);
//                    answer.append("L");
//                }else{
//                    if(hand.equals("right")){
//                        right = pattern.get(number);
//                        answer.append("R");
//                    }else {
//                        left = pattern.get(number);
//                        answer.append("L");
//                    }
//                }
//            }
//        }
//        System.out.println(answer.toString());
//        return answer.toString();
//    }