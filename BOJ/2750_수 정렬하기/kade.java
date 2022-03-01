import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cnt = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> queue = new PriorityQueue<>();

        for(int i = 0; i < cnt; i++) {
            queue.add(Integer.parseInt(br.readLine()));
        }
        while(!queue.isEmpty()) {
            System.out.println(queue.poll());
        }

    }
}