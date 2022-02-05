import java.io.BufferedReader;
import java.io.InputStreamReader;

public class 설탕배달 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt( br.readLine() );

		if( N == 4 || N == 7 ){
			sb.append(-1).append("\n");
		}else if( N % 5 == 0 ){
			sb.append( N / 5).append("\n");
		}else if( N % 5 == 1 || N % 5 == 3){
			sb.append( (N / 5) + 1).append("\n");
		}else if( N % 5 == 2 || N % 5 == 4){
			sb.append( (N / 5) + 2).append("\n");
		}
		System.out.println(sb);
	}
}
