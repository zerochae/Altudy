package programmers;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 미로탐색_2178 {

	static int [][] map;
	static int N;
	static int M;
	static boolean [][] visited;
	// x방향 배열 - 상하
	static int [] dx = {-1, 1, 0, 0};
	// y방향 배열 - 좌우
	static int [] dy = {0, 0, -1, 1};

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		map = new int[N][M];
		for(int i = 0; i < N; i++){
			String s = br.readLine();
			for(int j = 0; j < M; j++){
				map[i][j] = s.charAt(j) - '0';
			}
		}
		visited = new boolean[N][M];
		visited[0][0] = true;
		bfs(0, 0);
		System.out.println(map[N - 1][M - 1]);

	}
	public static void bfs(int x, int y){
		Queue<int []> q =  new LinkedList<>();
		q.add(new int[] {x, y});

		while(!q.isEmpty()){
			int newArr [] = q.poll();
			int newX = newArr[0];
			int newY = newArr[1];

			for(int i = 0; i < dx.length; i++){
				int nextX = newX + dx[i];
				int nextY = newY + dy[i];

				if(nextX < 0 || nextY < 0 || nextX >= N || nextY >= M)continue;
				if(visited[nextX][nextY]|| map[nextX][nextY] == 0) continue;

				q.add(new int[] {nextX, nextY});

				map[nextX][nextY] = map[newX][newY] + 1;

				visited[nextX][nextY] = true;
			}
		}

	}

}
