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
    //    1   2   3
    //    4   5   6
    //    7   8   9
    //    *   0   #
    //한칸의 거리는 1
    //같은 거리일 경우 왼손잡이인지 오른손잡이인지 판단

    // 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5
    public static String solution(int[] numbers, String hand){
        Person person = new Person("10", "12", hand);
        StringBuilder builder = new StringBuilder();

        for(int number : numbers){
            if(number == 0) number = 11;

            switch (number){
                //왼손
                case 1:
                    builder.append("L");
                    person.setLeftPosition("1");
                    break;
                case 4:
                    builder.append("L");
                    person.setLeftPosition("4");
                    break;
                case 7:
                    builder.append("L");
                    person.setLeftPosition("7");
                    break;

                //오른손
                case 3:
                    builder.append("R");
                    person.setRightPosition("3");
                    break;
                case 6:
                    builder.append("R");
                    person.setRightPosition("6");
                    break;
                case 9:
                    builder.append("R");
                    person.setRightPosition("9");
                    break;

                //가운데
                case 2:
                    calculateDistance(builder, person, 2);
                    break;
                case 5:
                    calculateDistance(builder, person, 5);
                    break;
                case 8:
                    calculateDistance(builder, person, 8);
                    break;
                case 11:
                    calculateDistance(builder, person, 11);
                    break;
            }
//            LRLLLRLLRRL 답안
//            LRLLLRLLLRL 내꺼
        }

        return builder.toString();
    }
    // 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5

    //1, 2, 3, 4, 5, 6, 7, 8, 9, 0
    public static void calculateDistance(StringBuilder builder, Person person, int num){
        String leftPosition = person.getLeftPosition();
        String rightPosition = person.getRightPosition();
        int substituteLeft = Math.abs(num - Integer.parseInt(leftPosition));
        int substituteRight = Math.abs(num - Integer.parseInt(rightPosition));

        int leftDistance = (substituteLeft % 3) + (substituteLeft / 3);
        int rightDistance = (substituteRight % 3) + (substituteRight / 3);

        if(leftDistance > rightDistance){
            builder.append("R");
            person.setRightPosition(num + "");
        } else if(leftDistance < rightDistance){
            builder.append("L");
            person.setLeftPosition(num + "");
        } else {
            if(person.getHand().equals("right")){
                builder.append("R");
                person.setRightPosition(num + "");
            } else {
                builder.append("L");
                person.setLeftPosition(num + "");
            }
        }
    }
}

class Person{
    String leftPosition;
    String rightPosition;
    String hand;

    Person(String left, String right, String hand){
        this.leftPosition = left;
        this.rightPosition = right;
        this.hand = hand;
    }

    public String getLeftPosition() {
        return leftPosition;
    }

    public void setLeftPosition(String leftPosition) {
        this.leftPosition = leftPosition;
    }

    public String getRightPosition() {
        return rightPosition;
    }

    public void setRightPosition(String rightPosition) {
        this.rightPosition = rightPosition;
    }

    public String getHand() {
        return hand;
    }
}
