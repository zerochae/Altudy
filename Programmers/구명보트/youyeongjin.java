package programmers.level2;

import java.util.Arrays;

public class 구명보트 {
    public static void main(String[] args) {
        //solution(new int[]{70,50,80,50},100);
        solution(new int[]{70,80,50},100);
    }

    public static int solution(int[] people, int limit) {
        Arrays.sort(people);

        int bigPeople = 0;
        int couple = 0;
        boolean bigPerson = false;

        while (bigPeople + couple*2 !=people.length){
            if(!bigPerson){
                if(people[people.length-bigPeople-1] > limit-40){
                    bigPeople++;
                    continue;
                }else {
                    bigPerson = true;
                }
            }

            if((people.length-bigPeople) % 2 == 1){
                bigPeople++;
            }else if(people[couple] + people[people.length-1-bigPeople-couple] > limit){
                bigPeople++;
            }else{
                couple++;
            }
        }

        return bigPeople + couple;
    }

}
