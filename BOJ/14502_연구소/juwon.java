import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 바이러스 좌표를 받을 class 선언
class dot{
	int x;
	int y;
	public dot(int y, int x){
		this.y = y;
		this.x = x;
	}
}

public class 연구소_14502 {

	// 정점
	static int x, y;
	// 지도와 복사할 지도 선언
	static int map[][], copyMap[][];
	// 상하
	static int dx[] = {0, 0, -1, 1};
	// 좌우
	static int dy[] = {1, -1, 0, 0};
	// 바이러스를 갖고있는 dot 타입 Queue 선언
	static Queue<dot> que;

	static int result;


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine(), " ");

		// 세로크기 n, 가로크기 m ...
		y = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());

		que = new LinkedList<>();
		map = new int[y][x];
		copyMap = new int[y][x];
		for(int i = 0; i < y; i++){
			st = new StringTokenizer(br.readLine(), " ");
			for(int j = 0; j < x; j++){
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		antiWall(0, 0);

		System.out.println(result);

	}
	
	// 브루트포스 알고리즘을 이용해 map에서 0인 곳에 벽을 세운다
	// 벽이 3개라면 바이러스를 퍼뜨리고 안전구역을 카운팅 한다
	public static void antiWall(int p_x, int p_y){
		// 벽이 3개면 바이러스 시작
		if(p_y == 3){
			setCopyMap();
			spreadBfs();
			result = Math.max(result, countIsSafe());
			return;
		}
		// 벽 3개를 세운다
		// 2차원 배열을 1차원 배열로 변환
		for(int i = p_x; i < y * x; i++){
			int newY = i / x;
			int newX = i % x;

			if(map[newY][newX] == 2|| map[newY][newX] == 1){
				continue;
			}
			map[newY][newX] = 1;
			antiWall(i + 1,  p_y + 1);
			map[newY][newX] = 0;
		}

	}

	// bfs를 이용해 que에있는 바이러스를 꺼내며 바이러스가 주변으로 퍼질 수 있다면 퍼뜨린다
	public static void spreadBfs(){
		while (!que.isEmpty()){
			dot virus = que.poll();
			for(int i = 0; i < 4; i++){
				int newY = virus.y + dy[i];
				int newX = virus.x + dx[i];

				if(newY >= 0 && newY < y && newX >= 0 && newX < x){
					// 0 이면 퍼뜨릴수 있음
					if(copyMap[newY][newX] == 0){
						copyMap[newY][newX] = 2;
						// 바이러스 심기
						que.offer(new dot(newY, newX));
					}
				}

			}
		}
	}

	public static int countIsSafe(){
		int safeCount = 0;
		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				if(copyMap[i][j] == 0){
					safeCount++;
				}
			}
		}
		return safeCount;
	}

	public static void setCopyMap(){
		for (int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				// 배열복사
				copyMap[i][j] = map[i][j];
				// 좌표값이 2라면 바이러스 따라서 바이러스 좌표를 넣는다
				if( copyMap[i][j] == 2){
					que.offer(new dot(i, j));
				}
			}
		}
	}

}
