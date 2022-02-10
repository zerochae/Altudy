package main.level_2;

public class 피보나치수 {

    public static int solution(int n) {
        int[] cache = new int[n + 1];
        cache[1] = 1;

        for(int i = 2; i < n + 1; i++) {
            cache[i] = cache[i - 1] % 1234567 + cache[i - 2] % 1234567;
        }

        return cache[n] % 1234567;
    }

    public static void main(String[] args) {
        solution(5);
    }
}
