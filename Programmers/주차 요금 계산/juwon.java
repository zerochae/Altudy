import java.util.*;

public class 주차_요금_계산 {
	public static void main(String[] args) {

		int [] fee = {180, 5000, 10, 600};

		String [] rec = {"05:34 5961 IN",
				"06:00 0000 IN", "06:34 0000 OUT",
				"07:59 5961 OUT", "07:59 0148 IN",
				"18:59 0000 IN", "19:09 0148 OUT",
				"22:59 5961 IN", "23:00 5961 OUT"};


		int[] solution = solution(fee, rec);

		for (int i : solution) {
			System.out.println(i);
		}

	}

	public static int[] solution(int[] fees, String[] records) {
		int b_time = fees[0];
		int b_fee = fees[1];
		int per_time = fees[2];
		int per_fee = fees[3];

		int lastTime = getMin("23:59");

		Map<String, Integer> parking = new HashMap<>();

		Map<String, Integer> times = new HashMap<>();

		List<String> cars = new ArrayList<>();

		for(String record : records){
			String [] rc = record.split(" ");
			int time = getMin(rc[0]);
			String carNum = rc[1];

			if(!cars.contains(carNum)){
				cars.add(carNum);
				times.put(carNum, 0);
			}
			if(parking.containsKey(carNum)){
				// 주차 되어있음
				int usedTime = times.get(carNum) + (time - parking.get(carNum));
				times.put(carNum, usedTime);
				parking.remove(carNum);
			}else{
				// 주차 안되어있음
				parking.put(carNum, time);
			}
		}

		int[] answer = new int[cars.size()];

		//차 번호순으로 정렬
		Collections.sort(cars);

		for(int i = 0; i < cars.size(); i++){
			answer[i] = b_fee;
			String ParkedCarNum = cars.get(i);

			// 주차한 시간 중 기본 요금 시간 제외
			int time = times.get(ParkedCarNum) - b_time;

			if(parking.containsKey(ParkedCarNum)){
				time += (lastTime - parking.get(ParkedCarNum));
			}

			if(time > 0){
				answer[i] += (Math.ceil(time / (per_time * 1.0)) * per_fee);
			}
		}
		return answer;
	}

	// 시간변환기
	public static int getMin(String time){
		String [] temp = time.split(":");
		int hour = Integer.parseInt( temp[0] )  * 60;
		int min = Integer.parseInt( temp[1]);
		return hour + min;
	}
}