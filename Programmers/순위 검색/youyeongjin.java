package programmers.level2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class 순위검색 {

    public static void main(String[] args) {
        solution(new String[]{"java backend junior pizza 150",
                        "python frontend senior chicken 210",
                        "python frontend senior chicken 150",
                        "cpp backend senior pizza 260",
                        "java backend junior chicken 80",
                        "python backend senior chicken 50"},
                new String[]{"java and backend and junior and pizza 100",
                        "python and frontend and senior and chicken 200",
                        "cpp and - and senior and pizza 250",
                        "- and backend and senior and - 150",
                        "- and - and - and chicken 100",
                        "- and - and - and - 150"});
    }

    public static int[] solution(String[] info, String[] query) {
        int[] answer = {};

        List<Person> people = new ArrayList<>();
        for(String str : info){
            String[] detail = str.split(" ");
            Person person = new Person(detail[0],detail[1],detail[2],detail[3],Integer.parseInt(detail[4]));
            people.add(person);
        }

        for(String str : query){
            int cnt = 0;
            List<Person> copy = new ArrayList<>(people);
            String[] detail = str.split(" ");
            if(!detail[0].equals("-")){
                for(Iterator<Person> iterator = copy.iterator(); iterator.hasNext();){
                    if(!iterator.next().lang.equals(detail[0])) iterator.remove();
                }
            }
            if(!detail[2].equals("-")){
                for(Iterator<Person> iterator = copy.iterator(); iterator.hasNext();){
                    if(!iterator.next().job.equals(detail[2])) iterator.remove();
                }
            }
            if(!detail[4].equals("-")){
                for(Iterator<Person> iterator = copy.iterator(); iterator.hasNext();){
                    if(!iterator.next().career.equals(detail[4])) iterator.remove();
                }
            }
            if(!detail[6].equals("-")){
                for(Iterator<Person> iterator = copy.iterator(); iterator.hasNext();){
                    if(!iterator.next().food.equals(detail[6])) iterator.remove();
                }
            }

            for(Person person: copy){
                if(person.score >= Integer.parseInt(detail[7])) cnt++;
            }

            answer = Arrays.copyOf(answer,answer.length+1);
            answer[answer.length-1] = cnt;
        }

        return answer;
    }

    static class Person{
        @Override
        public String toString() {
            return "Person{" +
                    "lang='" + lang + '\'' +
                    ", job='" + job + '\'' +
                    ", career='" + career + '\'' +
                    ", food='" + food + '\'' +
                    ", score=" + score +
                    '}';
        }

        String lang;
        String job;
        String career;
        String food;
        int score;

        public Person(String lang, String job, String career, String food, int score) {
            this.lang = lang;
            this.job = job;
            this.career = career;
            this.food = food;
            this.score = score;
        }
    }
}
