import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int arr[] = new int[N];
        int max = 0;
        double sum = 0;
        double output = 0;

        for(int i = 0; i < N; i++)
        {
            arr[i] = in.nextInt();
            sum += arr[i];
            if(arr[i] > max)
                max = arr[i];
        }
        in.close();
        
        output = ((sum / max) * 100) / N;
        System.out.println(output);
    }
}