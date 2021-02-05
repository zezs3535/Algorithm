package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ14888_연산자끼워넣기 {
	static int maxNum = Integer.MIN_VALUE;
	static int minNum = Integer.MAX_VALUE;
	static int[] arr;
	static int n;
	static void dfs(int plus, int minus, int mul, int div, int result, int idx) {
		if(idx==n-1) {
			maxNum = Math.max(maxNum, result);
			minNum = Math.min(minNum, result);
			return;
		}
		if(plus>0)dfs(plus-1, minus, mul, div, result + arr[idx+1], idx+1);
		if(minus>0)dfs(plus, minus-1, mul, div, result - arr[idx+1], idx+1);
		if(mul>0)dfs(plus, minus, mul-1, div, result * arr[idx+1], idx+1);
		if(div>0)dfs(plus, minus, mul, div-1, result / arr[idx+1], idx+1);
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		arr = new int[n];
		int[] ins = new int[4];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < 4; i++) {
			ins[i] = Integer.parseInt(st.nextToken());
		}
		dfs(ins[0], ins[1], ins[2], ins[3], arr[0], 0);
		bw.write(maxNum+"\n"+minNum);
		br.close();
		bw.flush();
		bw.close();
	}

}
