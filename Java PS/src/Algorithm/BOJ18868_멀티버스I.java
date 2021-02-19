package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ18868_멀티버스I {
	static int answer = 0;

	static void comp(int[] arr1, int[] arr2) {
		boolean flag = true;
		for (int i = 0; i < arr1.length; i++) {
			for (int j = i + 1; j < arr1.length; j++) {
				if (arr1[i] > arr1[j]) {
					if (arr2[i] <= arr2[j])
						flag = false;
				} else if (arr1[i] < arr1[j]) {
					if (arr2[i] >= arr2[j])
						flag = false;
				} else {
					if (arr2[i] != arr2[j])
						flag = false;
				}

			}
		}
		if (flag)
			answer++;
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[][] arr = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				comp(arr[i], arr[j]);
			}
		}
		bw.write(answer + "");
		br.close();
		bw.flush();
		bw.close();
	}
}
