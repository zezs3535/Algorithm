package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ12852_1로만들기2 {
	static int[] cnt;
	static int[] before;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		Queue<Integer> q = new LinkedList<>();
		int n = Integer.parseInt(st.nextToken());
		cnt = new int[1000001];
		before = new int[1000001];
		cnt[1] = 0;
		before[1] = 0;
		cnt[2] = 1;
		before[2] = 1;
		cnt[3] = 1;
		before[3] = 1;
		if (n == 1) {
			bw.write(0 + "\n" + 1);
		} else {
			for (int i = 4; i <= n; i++) {
				int min = cnt[i - 1];
				boolean flag = false;
				before[i] = i-1;
				if (i % 2 == 0) {
					if(cnt[i/2]<min) {
						min = cnt[i/2];
						before[i] = i/2;
					}
				}
				if(i%3==0) {
					if(cnt[i/3]<min) {
						min = cnt[i/3];
						before[i] = i/3;
					}
				}
				cnt[i] = min+1;
			}
			bw.write(cnt[n]+"\n"+n+" ");
			int cur = n;
			while (true) {
				bw.write(before[cur]+" ");
				cur = before[cur];
				if (cur == 1) {
					break;
				}
			}
		}
		br.close();
		bw.flush();
		bw.close();
	}
}
