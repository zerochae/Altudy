package programmers.level2;

public class 타겟넘버 {
    static int answer = 0;

    public static void main(String[] args) {
        solution(new int[]{1,1,1,1,1},5);
        solution(new int[]{4,1,2,1},2);
    }

    public static int solution(int[] numbers, int target) {
        dfs(numbers,target,0,0);
        return answer;
    }

    public static void dfs(int[] numbers,int target,int start,int sum){
        if(start == numbers.length){
            if(sum == target) answer++;
            return;
        }

        sum+=numbers[start];

        dfs(numbers,target,start+1,sum);
        sum-=numbers[start];
        sum+=(-1 * numbers[start]);

        dfs(numbers,target,start+1,sum);

    }
}
