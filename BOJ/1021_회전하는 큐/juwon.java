import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class TurnningQueue_1021 {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		LinkedList<Integer> deque = new LinkedList<>();
		
		// 2번과 3번연산의 횟수 누적을 위한 변수
		int cnt = 0;

		StringTokenizer st = new StringTokenizer(br.readLine(), " ");

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		for(int i = 1; i <= N; i++){
			deque.offer(i);
		}

		// 뽑을 수를 저장할 배열
		int [] seq = new int[M];

		st = new StringTokenizer(br.readLine(), " ");

		for(int i = 0; i < M; i++){
			seq[i] = Integer.parseInt(st.nextToken());
		}

		for(int i = 0; i < M; i++){
			// 뽑을 수의 Idx를 저장하는 변수
			int targetIdx = deque.indexOf(seq[i]);

			// 이분탐색
			int halfIdx;

			// 크기가 짝수인 경우 덱의 절반 크기 -1
			if(deque.size() % 2 == 0){
				halfIdx = deque.size() / 2 - 1;
			}else{
				// 홀수인 경우 덱의 절반
				halfIdx = deque.size() / 2;
			}

			// 중간지점보다 뽑을 IDX가 앞에있는경우와 중간 지점인 경우
			if(targetIdx <= halfIdx){
				for(int j = 0; j < targetIdx; j++){
					int temp = deque.pollFirst();
					deque.offerLast(temp);
					cnt++;
				}
			}else{
				// 중간 지점보다 타겟의 위치가 뒤에있는 경우
				for(int j = 0; j < deque.size() - targetIdx; j++){
					int temp = deque.pollLast();
					deque.offerFirst(temp);
					cnt++;
				}
			}
			// 연산이 끝나면 맨 앞의 원소를 삭제함
			deque.pollFirst();
		}
		System.out.println(cnt);
	}
}
