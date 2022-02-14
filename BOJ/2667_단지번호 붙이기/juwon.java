package BackJoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class 단지번호붙이기_2667 {
	// dfs와 bfs 두개로 풀어보자
	// 상하
	static int dx[] = {0, 0, 1, -1};
	// 좌우
	static int dy[] = {1, -1, 0, 0};
	static int [] aparts = new int[25 * 25];
	static int n;
	static int apartNum = 0;
	static boolean[][] visited;
	static int [][] map;


	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		n = Integer.parseInt(br.readLine());

		map = new int[n][n];

		visited = new boolean[n][n];

		for(int i = 0; i < n; i++){
			String s = br.readLine();
			for(int j = 0; j < n; j++){
				// 문자열 반환 charat 을 - 0(아스키코드 48)해서 int형으로
				map[i][j] = s.charAt(j) - '0';
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j =0; j < n; j++){
				if(map[i][j] == 1 && !visited[i][j]){
					// 1이면서 방문하지 않는 좌표이면 단지수 1증가
					apartNum++;
//					System.out.println(i + ""+ j);
//					dfs(i, j);
					bfs(i, j);
				}
			}
		}

		// 정렬해서 출력
		Arrays.sort(aparts);
		sb.append(apartNum).append("\n");
		for(int i = 0; i < aparts.length; i++){
			if(!(aparts[i] == 0)){
				sb.append(aparts[i]).append("\n");
			}
		}
		System.out.println(sb);
	}
	public static void dfs(int x, int y){
		visited[x][y] = true;
		aparts[apartNum]++;
		for(int i = 0; i < 4; i++){
			int newX = x + dx[i];
			int newY = y + dy[i];

			if(newX >= 0 && newY >= 0 && newX < n && newY <n){
				if(map[newX][newY] == 1 && !visited[newX][newY]) {
					dfs(newX, newY);
				}
			}
		}
	}
	
	public static void bfs(int x, int y){
		Queue<int []> queue = new LinkedList<>();
		queue.add(new int [] {x, y});
		visited[x][y] = true;
		aparts[apartNum]++;
		
		while(!queue.isEmpty()){
			int currentX = queue.peek()[0];
			int currentY = queue.peek()[1];

			queue.poll();
			for(int i = 0; i < 4; i++){
				int newX = currentX + dx[i];
				int newY = currentY + dy[i];
				
				if(newX >= 0 && newY >= 0 && newX < n && newY < n){
					// 1이면서 방문하지 않은곳
					if(map[newX][newY] == 1 && !visited[newX][newY]){
						queue.add(new int[] {newX, newY});
						visited[newX][newY] = true;
						aparts[apartNum]++;
					}
				}
				
			}
		}
	}
}
