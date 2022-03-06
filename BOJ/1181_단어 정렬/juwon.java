import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());

		String [] arr = new String[N];

		for(int i = 0; i < N; i++){
			arr[i] = br.readLine();
		}
		
		// 익명객체 활용
		Arrays.sort(arr, new Comparator<String>(){
			public int compare(String s1, String s2){
				if(s1.length() == s2.length()){
					// 길이가 같을 경우 사전순으로 정렬
					return s1.compareTo(s2);
				}else{
					// 아닐경우 길이순으로 정렬
					return s1.length() - s2.length();
				}
			}
		});
		
		// 첫 요소 붙인 후
		sb.append(arr[0]).append("\n");

		for(int i = 1; i < N; i++){
			// 2번째 요소부터 첫요소와 비교해 중복되지 않는 단어만 출력함
			if(!arr[i].equals(arr[i-1])){
				sb.append(arr[i]).append("\n");
			}
		}
		System.out.println(sb);
	}
}
