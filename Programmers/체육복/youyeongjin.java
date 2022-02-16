package programmers.level1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class 체육복 {
    public static void main(String[] args) {
        solution(5,new int[]{2,4},new int[]{1,3,5});
        solution(5,new int[]{2,4},new int[]{3});
        solution(3,new int[]{3},new int[]{1});
    }

    public static int solution(int n, int[] lost, int[] reserve) {
        List<Integer> lostList = Arrays.stream(lost).boxed().collect(Collectors.toList());
        List<Integer> reserveList = Arrays.stream(reserve).boxed().collect(Collectors.toList());
        List<Integer> duplicate = new ArrayList<>();
        for(Integer lostItem : lostList){
            if(reserveList.contains(lostItem)){
                duplicate.add(lostItem);
            }
        }
        for(Integer item : duplicate){
            lostList.remove(item);
            reserveList.remove(item);
        }
        for(Integer i=1 ; i<=n; i++){
            if(reserveList.contains(i)){
                if(lostList.contains(i-1)){
                    lostList.remove((Integer)(i-1));
                }else if(lostList.contains(i+1)){
                    lostList.remove((Integer)(i+1));
                }
            }
        }
        System.out.println(n-lostList.size());
        return n-lostList.size();
    }
}
