import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class kade {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<String> list = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            String[] students = br.readLine().split(" ");
            int[] score = new int[students.length - 1];
            double total = 0;
            for(int j = 0; j < score.length; j++) {
                score[j] = Integer.parseInt(students[j + 1]);
                total += score[j];
            }
            total = total / Integer.parseInt(students[0]);
            double cnt = 0;
            for(int s : score) {
                if (s > total) {
                    cnt++;
                }
            }
            list.add(String.format("%.3f%%", cnt / Integer.parseInt(students[0]) * 100));
        }
        list.forEach(System.out::println);
    }

}
