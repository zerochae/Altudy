import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 정수삼각형_1932 {

	static int [][] arr;
	static Integer [][] dp;
	static int N;

	public static void main(String[] args) throws  Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());

		arr = new int[N][N];
		dp = new Integer[N][N];
		StringTokenizer st;
		for(int i = 0; i < N; i++){
			st = new StringTokenizer(br.readLine(), " ");

			for(int j = 0; j < i + 1; j++){
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for(int i = 0; i < N; i++){
			dp[N - 1][i] = arr[N - 1][i];
		}
		System.out.println(find(0, 0));

	}
	public static int find(int depth, int idx){
		if( depth == N - 1){
			return dp[depth][idx];
		}
		if(dp[depth][idx] == null){
			dp[depth][idx] = Math.max(find(depth + 1, idx), find(depth + 1, idx + 1)) + arr[depth][idx];
		}
		return dp[depth][idx];
	}


}
