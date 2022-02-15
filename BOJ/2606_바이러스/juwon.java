import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 바이러스2606 {

	// 각 정점(컴퓨터 좌표)간 탐색 경로를 저장할 배열변수
	static int map[][];
	// 방문한 배열
	static boolean visit[];
	// n => 컴퓨터 좌표, m => 컴퓨터 간의 선, v => 시작하는 정점( 컴퓨터 좌표 )
	static int n, m, v;
	// 정점과 연결된 바이러스가 걸리는 컴퓨터의 수
	static int count = 0;

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringBuilder sb = new StringBuilder();
		
		// 정점 개수 ( 컴퓨터의 수 )
		n = Integer.parseInt(br.readLine());
		// 연결된 컴퓨터의 수 ( 간선 )
		m = Integer.parseInt(br.readLine());
		
		// 시작 정점 
		v = 1;
		
		// 정점간 탐색 경로를 저장할 배열
		map = new int[n+1][n+1];

		visit = new boolean[n+1];

		for(int i = 0; i < m; i++){
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			map[a][b] = 1;
			map[b][a] = 1;
		}
		sb.append(dfs(1)).append("\n");
		// sb.append(bfs(1)).append("\n");

		System.out.println(sb);
	}
	public static int dfs(int x){
		visit[x] = true;
		for(int i = 1; i <= n; i++){
			if(map[x][i] == 1 && !visit[i]){
				count++;
				dfs(i);
			}
		}
		return count;
	}
	public static int bfs(int x){
		Queue<Integer> queue = new LinkedList<>();
		queue.offer(x);
		visit[x] = true;
		while(!queue.isEmpty()){
			int newX = queue.poll();
			for(int i = 1; i <= n; i++){
				if(map[newX][i] == 1 && !visit[i]){
					queue.offer(i);
					visit[i] = true;
					count++;
				}
			}
		}
		return count;
	}
}
