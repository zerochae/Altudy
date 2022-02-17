import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 숨바꼭질_1697 {

	// 1차원 배열을 이용한 bfs 문제이다
	// 수빈
	static int N;
	// 동생
	static int K;
	// 위치
	static int [] arr;
	// 방문여부 ( 탐색 )
	static boolean [] visited;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		// 1초 후 수빈이의 위치 점화식
		arr = new int[Math.max(N, K) * 2 + 1];
		visited = new boolean[Math.max(N, K) * 2 + 1];

		bfs();

		System.out.println(arr[K]);

	}

	public static void bfs(){
		Queue<Integer> queue = new LinkedList<>();

		int maxValue = Math.max(N, K);

		queue.offer(N);

		visited[N] = true;

		while(!queue.isEmpty()){
			int curVal = queue.poll();
			for(int i = 0; i < 3; i++){
				int nextVal = 0;

				if( i == 0 ){
					nextVal = curVal - 1;
				}else if ( i == 1 ){
					nextVal = curVal + 1;
				}else{
					nextVal = curVal * 2;
				}
				
				// 순간이동을 하게되는 경우와 걷는 경우
				if( nextVal >= 0 && nextVal < 2 * maxValue && !visited[nextVal]){
					queue.offer(nextVal);
					visited[nextVal] = true;
					arr[nextVal] = arr[curVal] + 1;
				}

			}

		}

	}
}
