package Algorithm;

import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class BOJ1037_약수 {

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
		if (n == 1) {
			System.out.println(arr[0] * arr[0]);
		} else {
			System.out.println(arr[0] * arr[n - 1]);
		}
	}
}
