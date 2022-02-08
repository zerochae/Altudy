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