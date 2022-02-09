import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class DFS_BFS_1260 {

	static int map[][];
	static boolean [] visit;
	static int n, m, v;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine(), " ");


		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		v = Integer.parseInt(st.nextToken());

		map = new int[n + 1][n + 1];
		visit = new boolean[n + 1];

		for(int j = 0; j < n + 1; j++){
			// 이중배열을 0으로 초기화
			Arrays.fill(map[j], 0);
		}
		// 방문 정보를 false로 초기화
		Arrays.fill(visit, false);

		for(int i = 0; i < m; i++){
			st = new StringTokenizer(br.readLine(), " ");

			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			map[a][b] = 1;
			map[b][a] = 1;
		}
		dfs(v);
		sb.append("\n");
		Arrays.fill(visit, false);
		bfs(v);
		System.out.println(sb);
	}
	
	public static void dfs(int i ){
		visit[i] = true;
		sb.append(i + " ");
		for(int j = 1; j < n + 1; j++){
			// 내가 찾은 경로가 만약에 다른 경로가 있으면 바로 다음 곳으로 이동시켜서 만약에 없으면
			// 다시 돌아오는 방식
			if(map[i][j] == 1 && !visit[j]){
				dfs(j);
			}
		}
	}

	public static void bfs(int i){
		Queue<Integer> q = new LinkedList<Integer>();
		q.offer(i);
		visit[i] = true;
		// 방문한 위치를 알아야하니 체크하기위한 visit 필요
		while(!q.isEmpty()){
			int temp = q.poll();
			
			// 첫 번째 방문한 위치는 뺀다.
			sb.append(temp + " ");
			
			for(int k = 1; k <= n; k++){
				if(map[temp][k] == 1 && !visit[k]){
					q.offer(k);
					// true라면 방문이 되었음
					visit[k] = true;
				}
			}
		}

	}
}
