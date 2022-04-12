import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	static int arr[][];
	static int test[];
	static int result = Integer.MAX_VALUE;
	static int start = 0;
	static int link = 0;
	static int n;
	static boolean visit[];

	public static void main(String[] args) throws Exception, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());

		arr = new int[n][n];
		test = new int[n / 2];
		visit = new boolean[n];

		for (int i = 0; i < n; i++) {
			String input[] = br.readLine().split(" ");
			for (int j = 0; j < n; j++) {
				arr[i][j] = Integer.parseInt(input[j]);
			}
		}

		dfs(0);
		
		System.out.println(result);

	}

	private static void dfs(int depth) {

		if (depth == n / 2) {
			team(test);

//			for(int value : test) {
//				System.out.print(value + " ");
//			}
//			System.out.println();
			return;
		}

		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				visit[i] = true;
				test[depth] = i + 1;
				dfs(depth + 1);

				for (int j = i + 1; j < n; j++) {
					visit[j] = false;
				}
			}
		}
	}

	private static void team(int startTeam[]) {

		boolean isMyTeam[] = new boolean[(startTeam.length * 2) + 1];
		int linkTeam[] = new int[n / 2];

		for (int i = 0; i < startTeam.length; i++) {
			isMyTeam[startTeam[i]] = true;
		}
		int nextIndex = 1;
		for (int i = 0; i < linkTeam.length; i++) {
			loop: for (int j = nextIndex; j < isMyTeam.length; j++) {
				if (!isMyTeam[j]) {
					linkTeam[i] = j;
					nextIndex = j + 1;
					break loop;
				}
			}
		}
//		System.out.println("startTeam : " + Arrays.toString(startTeam));
//		System.out.println("linkTeam : " + Arrays.toString(linkTeam));
		score(startTeam,linkTeam);
//		System.out.println("======================================");

	}

	private static void score(int[] startTeam, int[] linkTeam) {
		int sum_start = 0;
		for(int i =0; i<startTeam.length; i++) {
			for(int j =0; j<startTeam.length; j++) {
				if(i != j) {
				sum_start += arr[startTeam[i]-1][startTeam[j]-1] + arr[startTeam[j]-1][startTeam[i]-1];
				}
			}
		}
		
		int sum_link = 0;
		for(int i =0; i<linkTeam.length; i++) {
			for(int j =0; j<linkTeam.length; j++) {
				if(i != j) {
					sum_link += arr[linkTeam[i]-1][linkTeam[j]-1] + arr[linkTeam[j]-1][linkTeam[i]-1];
				}
			}
		}
//		System.out.print("sum_start : " + sum_start +" ");
//		System.out.println("sum_link : " + sum_link);
//		System.out.println("start - link : "+ Math.abs(sum_start-sum_link));
		result = Math.min(result, Math.abs(sum_start-sum_link)/2);
//		System.out.println("result : "+ result);
	}
}
