import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static int arr[];
	static int oper[];
	static int n;
	static int MAX = Integer.MIN_VALUE;
	static int MIN = Integer.MAX_VALUE;
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine()); // n개의 수 입력
		
		arr = new int [n]; // n개의 수열을 담을 arr 선언
		oper = new int [4];
		String inputNum[] = br.readLine().split(" ");
		
		for(int i =0; i<n; i++) {
			arr[i] = Integer.parseInt(inputNum[i]); // n개의 수열 A1, A2, ... , An 입력
		}
		
		String inputOper[] = br.readLine().split(" ");
		
		for(int i =0; i<4; i++) { 
			oper[i] = Integer.parseInt(inputOper[i]); // 합이 n-1인 연산자의 수 입력 차례대로 덧셈,뺄셈,곱셈,나눗셈
		}
		
		dfs(arr[0],1);
		
		System.out.println(MAX);
		System.out.println(MIN);
		
		
	}

	private static void dfs(int value,int depth) {
		
		if(n == depth) { 
			MAX = Math.max(value, MAX);
			MIN = Math.min(value, MIN);
			return;
		}
		
		for(int i=0; i<4; i++) {
			if(oper[i] > 0) {
				oper[i]--;
				switch(i) {
				case 0 : dfs(value + arr[depth] , depth+1); break;
				case 1 : dfs(value - arr[depth] , depth+1); break;
				case 2 : dfs(value * arr[depth] , depth+1); break;
				case 3 : dfs(value / arr[depth] , depth+1); break;
				}
				oper[i]++;
			}
		}
	}
}