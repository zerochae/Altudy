import java.util.Arrays;

public class 거리두기_확인하기 {

	public static final int ROW = 5;
	public static final int COL = 5;

	public static void main(String[] args) {
		
		// 대기실은 5개이며, 각 대기실은 5x5 크기입니다.
		// 거리두기를 위해 배열간 거리가 2이하로 앉기 금지
		// 응시자가 앉아있는 자리 사이가 파티션으로 되어있는 경우에는 허용
		// 거리두기를 지키면 1 한명이라도 안지키면 0 리턴
		
		// p => 응시자
		// o => 빈 테이블
		// x => 파티션

		// 1차원 정수 배열에 5개의 원소를 담아서 return

		String [][]temp = {
				{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}
				, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}
				, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}
				, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}
				, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
		};

		int [] res = solution(temp);

		System.out.println(Arrays.toString(res));

	}

	public static int [] solution(String [][] places){
		int [] answer = new int[places.length];

		for (int i = 0; i < places.length; i++){
			String [] arr = places[i];
			boolean flag = false;
			for(int j = 0; j < ROW; j++){
				for(int k = 0; k < COL; k++){
					// 앉은자리
					if(arr[j].charAt(k)=='P'){
						if(isManhataan(j, k, arr)){
							flag = true;
							break;
						}
					}
				}
				if (flag){
					// 맨하튼 거리에있으면
					answer[i] = 0;
					break;
				}
			}
			if (!flag){
				// 맨하튼 거리에 없으면
				answer[i] = 1;
			}
		}
		return answer;
	}

	public static boolean isManhataan(int x, int y,String [] arr){
		// 상하좌우 확인하기 위한 mi, mj int 배열 선언
		int [] mi = {0, 0, 1, -1};
		int [] mj = {1, -1, 0, 0};

		for(int i = 0; i < mi.length; i ++){
			int NewI = x + mi[i];
			int NewJ = y + mj[i];

			if( NewI < 0 || NewI >= ROW || NewJ < 0 || NewJ >= COL)continue;
			if(arr[NewI].charAt(NewJ) == 'P') return true;

		}
		// 상하좌우 맨하튼 거리 2 확인
		int [] mi2 = {0, 0, 2, -2};
		int [] mj2 = {2, -2, 0, 0};

		for(int i = 0; i < mi2.length; i++){
			int NewI = x + mi2[i];
			int NewJ = y + mj2[i];


			if( NewI < 0 || NewI >= ROW || NewJ < 0 || NewJ >= COL ) continue;

			int tmpi = (x + NewI) / 2;
			int tmpj = (y + NewJ) / 2;

			if(arr[NewI].charAt(NewJ) == 'P'){
				if(arr[tmpi].charAt(tmpj) != 'X'){
					return true;
				}
			}
		}

		// 대각선확인을 위한 mi3 mj3 배열변수
		int [] mi3 = {1, 1, -1, -1};
		int [] mj3 = {1, -1, 1, -1};

		for(int i = 0; i < mi3.length; i++){
			int NewI = x + mi3[i];
			int NewJ = y + mj3[i];

			if(NewI < 0 || NewI >= ROW || NewJ < 0 || NewJ >= COL) continue;
			if(arr[NewI].charAt(NewJ) == 'P'){
				if(!(arr[x].charAt(NewJ) == 'X' && arr[NewI].charAt(y) == 'X')){
					return true;
				}
			}
		}
		return false;
	}

}
