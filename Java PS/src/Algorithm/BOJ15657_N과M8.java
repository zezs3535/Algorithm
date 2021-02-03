package Algorithm;

import java.util.Arrays;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ15657_N과M8 {
	static int n;
	static int m;
	static int[] num; // 1, 2, 3.... 숫자
	static int[] arr; // 값을 담아서 출력할 배열
	static boolean[] v;
	static BufferedReader br;
	static BufferedWriter bw;

	private static void permu(int idx, int k) throws Exception {
		if (k == m) {
			for (int i : arr) {
				bw.write(i + " ");
			}
			bw.write("\n");
			return;
		}
		for (int i = 0; i < n; i++) {
			if(k!=0 && arr[k-1] > num[i])continue;
			arr[k] = num[i];
			permu(idx,k+1);
		}
	}

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine()); // 01010001
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		num = new int[n];
		arr = new int[m];
		v = new boolean[n];
		for (int i = 0; i < n; i++) {
			num[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(num);
		permu(0, 0);
		br.close();
		bw.flush();
		bw.close();
	}

}
