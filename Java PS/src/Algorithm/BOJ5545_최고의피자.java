package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class BOJ5545_최고의피자 {

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int dp = Integer.parseInt(st.nextToken()); //도우 가격
		int tp = Integer.parseInt(st.nextToken()); //토핑 가격
		st = new StringTokenizer(br.readLine());
		int dc = Integer.parseInt(st.nextToken()); //도우 칼로리
		int ans = dc/dp;
		Integer[] tc = new Integer[t]; //토핑 칼로리
		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			tc[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(tc, Collections.reverseOrder());
		int ttc = dc; //토핑 총 칼로리
		int ttp = dp; //토핑 총 가격
		for (int i = 0; i < t; i++) {
			if((tc[i] + ttc) / (tp + ttp) >= ans) {
				ans = (tc[i] + ttc) / (tp + ttp);
				ttc += tc[i];
				ttp += tp;
			}
			else {
				break;
			}
		}
		bw.write(ans+"");
		br.close();
		bw.flush();
		bw.close();
	}
}
