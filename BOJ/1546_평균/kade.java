import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] inputs = br.readLine().split(" ");
        double[] score = new double[inputs.length];
        for(int i = 0; i < inputs.length; i++) {
            score[i] = Double.parseDouble(inputs[i]);
        }
        Arrays.sort(score);
        double answer = 0;
        for(int i = 0; i < score.length; i++) {
            score[i] = score[i] / score[score.length - 1] * 100;
            answer += score[i];
        }

        System.out.println(answer / n);
    }
}
