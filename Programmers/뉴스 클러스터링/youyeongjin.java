package programmers.level2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class 뉴스클러스터링 {
    public static void main(String[] args) {
        //solution("FRANCE","french");
        //solution("handshake","shake hands");
        solution("aa1+aa2","AAAA12");
        //solution("E=M*C^2","e=m*c^2");
    }

    public static int solution(String str1, String str2) {
        str1 = str1.toUpperCase();
        str2 = str2.toUpperCase();

        List<String> list1 = new ArrayList<>();
        List<String> list2 = new ArrayList<>();

        List<String> union = new ArrayList<>();
        List<String> intersection = new ArrayList<>();

        for(int i = 0; i < str1.length()-1; i++) {
            char a = str1.charAt(i);
            char b = str1.charAt(i+1);

            if(Character.isLetter(a) && Character.isLetter(b)) {
                String str = "" + a + b;
                list1.add(str);
            }
        }

        for(int i = 0; i < str2.length()-1; i++) {
            char a = str2.charAt(i);
            char b = str2.charAt(i+1);

            if(Character.isLetter(a) && Character.isLetter(b)) {
                list2.add(""+a+b);
            }
        }

        Collections.sort(list1);
        Collections.sort(list2);

        for(String s : list1) {
            if(list2.remove(s)) {
                intersection.add(s);
            }
            union.add(s);
        }

        for(String s : list2) {
            union.add(s);
        }

        double a = intersection.size();
        double b = union.size();

        double jacquard  = 0;

        if(union.size() == 0) jacquard = 1;
        else jacquard = (double) intersection.size() / (double) union.size();

        return (int) (jacquard * 65536);
    }
}
