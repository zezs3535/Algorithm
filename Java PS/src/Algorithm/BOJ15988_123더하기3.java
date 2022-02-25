package Algorithm;

import java.io.FileInputStream;
import java.util.Scanner;

public class BOJ15988_123더하기3 {
	
	static int MOD = 1000000009;
	static long[] arr = new long[1000001];
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 4;
		for (int j = 4; j <= 1000000; j++) {
			arr[j] = (arr[j-1] + arr[j-2] + arr[j-3]) % MOD;
		}
		for (int i = 0; i < n; i++) {
			int num = sc.nextInt();
			System.out.println(arr[num]);
		}
	}
}
