package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ10211_MaximumSubarray {

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		for (int test = 1; test <= t; test++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int[] arr = new int[n];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			int totalsum = Integer.MIN_VALUE;
			int sum = 0;
			for (int i = 0; i < n; i++) {
				sum+=arr[i];
				totalsum=Math.max(sum, totalsum);
				if(sum<0)sum=0;
			}
			System.out.println("#" + test+" "+totalsum);
		}
		br.close();
		bw.flush();
		bw.close();
	}
}
